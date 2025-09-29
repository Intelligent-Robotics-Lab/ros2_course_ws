#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_twist;
void timerCallback();

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("turtle_timer");

  pub_twist = node->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 1);
  auto timer = node->create_wall_timer(std::chrono::milliseconds(500), timerCallback);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void timerCallback()
{
  geometry_msgs::msg::Twist twist_msg;
  twist_msg.linear.x = 1.0;
  twist_msg.angular.z = 1.0;
  pub_twist->publish(twist_msg);
}