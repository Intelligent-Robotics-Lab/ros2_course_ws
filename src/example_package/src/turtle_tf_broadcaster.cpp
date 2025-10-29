#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "turtlesim/msg/pose.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2/LinearMath/Vector3.hpp"
#include "tf2/LinearMath/Transform.hpp"
#include "tf2_ros/transform_broadcaster.hpp"

std::shared_ptr<rclcpp::Node> node;
std::shared_ptr<tf2_ros::TransformBroadcaster> broadcaster;

void turtle_pose_to_tf(const std::shared_ptr<turtlesim::msg::Pose> msg);

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  node = std::make_shared<rclcpp::Node>("turtle_tf_broadcaster");
  node->declare_parameter<std::string>("turtle_name", "turtle");
  broadcaster = std::make_shared<tf2_ros::TransformBroadcaster>(node);

  auto pose_sub = node->create_subscription<turtlesim::msg::Pose>(node->get_parameter("turtle_name").as_string() + "/pose", 10, turtle_pose_to_tf);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void turtle_pose_to_tf(const std::shared_ptr<turtlesim::msg::Pose> msg)
{
  tf2::Transform transform;
  geometry_msgs::msg::TransformStamped transformStamped;

  transformStamped.header.stamp = node->get_clock()->now();
  transformStamped.header.frame_id = "origin";
  transformStamped.child_frame_id = node->get_parameter("turtle_name").as_string();

  tf2::Vector3 translation;
  translation.setValue(msg->x, msg->y, 0);
  transform.setOrigin(translation);

  tf2::Quaternion rotation;
  rotation.setRPY(0, 0, msg->theta);
  transform.setRotation(rotation);

  transformStamped.transform.translation.x = transform.getOrigin().x();
  transformStamped.transform.translation.y = transform.getOrigin().y();
  transformStamped.transform.translation.z = transform.getOrigin().z();
  transformStamped.transform.rotation.x = transform.getRotation().x();
  transformStamped.transform.rotation.y = transform.getRotation().y();
  transformStamped.transform.rotation.z = transform.getRotation().z();
  transformStamped.transform.rotation.w = transform.getRotation().w();

  broadcaster->sendTransform(transformStamped);
}