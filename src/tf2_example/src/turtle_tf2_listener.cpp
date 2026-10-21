#include <chrono>
#include <cmath>
#include <memory> 
#include <string>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"

rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
std::shared_ptr<tf2_ros::TransformListener> tf_listener;
tf2_ros::Buffer::SharedPtr tf_buffer;

std::string target_frame;


void timerCallback(){
  const std::string from_frame_rel = target_frame;
  const std::string to_frame_rel = "turtle2";

  geometry_msgs::msg::TransformStamped transform;

  try{
    transform = tf_buffer->lookupTransform(to_frame_rel, from_frame_rel, tf2::TimePointZero);
  } catch (const tf2::TransformException &ex){
    return;
  }

  geometry_msgs::msg::Twist msg;
  msg.angular.z = std::atan2(transform.transform.translation.y, transform.transform.translation.x);
  msg.linear.x = 0.5 * std::sqrt(std::pow(transform.transform.translation.x, 2) + std::pow(transform.transform.translation.y, 2));

  publisher->publish(msg);
}


int main(int argc, char **argv){
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("turtle_tf2_listener");
  target_frame = node->declare_parameter<std::string>("target_frame", "turtle1");

  tf_buffer = std::make_shared<tf2_ros::Buffer>(node->get_clock());
  tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);

  publisher = node->create_publisher<geometry_msgs::msg::Twist>("turtle2/cmd_vel", 1);

  auto timer = node->create_wall_timer(std::chrono::milliseconds(1000), timerCallback);

  rclcpp::spin(node);
  rclcpp::shutdown();
}
