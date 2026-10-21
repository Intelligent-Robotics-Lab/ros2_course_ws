#include <functional>
#include <memory>
#include <string>
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "turtlesim/msg/pose.hpp"

void handle_turtle_pose(turtlesim::msg::Pose::ConstSharedPtr msg, 
                          const std::string &turtle_name,
                          const rclcpp::Node::SharedPtr &node,
                          const std::shared_ptr<tf2_ros::TransformBroadcaster> &tf_broadcaster){
  geometry_msgs::msg::TransformStamped tf;
  tf.header.stamp = node->get_clock()->now();
  tf.header.frame_id = "world";
  tf.child_frame_id = turtle_name;

  tf.transform.translation.x = msg->x;
  tf.transform.translation.y = msg->y;
  tf.transform.translation.z = 0;
  
  tf2::Quaternion q;
  q.setRPY(0,0, msg->theta);
  tf.transform.rotation.x = q.x();
  tf.transform.rotation.y = q.y();
  tf.transform.rotation.z = q.z();
  tf.transform.rotation.w = q.w();

  tf_broadcaster->sendTransform(tf);
}

int main(int argc, char** argv){
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("turtle_tf2_broadcaster");
  const auto turtlename1 = node->declare_parameter<std::string>("turtlename1", "turtle1");
  const auto turtlename2 = node->declare_parameter<std::string>("turtlename2", "turtle2");

  auto tf_broadcaster = std::make_shared<tf2_ros::TransformBroadcaster>(*node);

  const auto topic_name1 = "/" + turtlename1 + "/pose";
  const auto topic_name2 = "/" + turtlename2 + "/pose";
  
  using PoseCallback = std::function<void(turtlesim::msg::Pose::ConstSharedPtr)>;

  PoseCallback pose_callback1 = [node, tf_broadcaster, turtlename1](turtlesim::msg::Pose::ConstSharedPtr msg){
    handle_turtle_pose(msg,turtlename1, node, tf_broadcaster);
  }; 

  PoseCallback pose_callback2 = [node, tf_broadcaster, turtlename2](turtlesim::msg::Pose::ConstSharedPtr msg){
    handle_turtle_pose(msg,turtlename2, node, tf_broadcaster);
  }; 

  auto subscription1 = node->create_subscription<turtlesim::msg::Pose>(topic_name1, 1, pose_callback1);
  auto subscription2 = node->create_subscription<turtlesim::msg::Pose>(topic_name2, 1, pose_callback2);

  rclcpp::spin(node);
  rclcpp::shutdown();
}