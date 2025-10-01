#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_twist;
rclcpp::Node::SharedPtr node;
void timerCallback();

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("turtle_timer");
  node->declare_parameter<int>("counter", 0);

  pub_twist = node->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 1);
  auto timer = node->create_wall_timer(std::chrono::milliseconds(500), timerCallback);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void timerCallback()
{
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%ld", node->get_parameter("counter").as_int());
  node->set_parameter(rclcpp::Parameter("counter", node->get_parameter("counter").as_int() + 1));
  geometry_msgs::msg::Twist twist_msg;
  twist_msg.linear.x = 1.0;
  twist_msg.angular.z = 1.0;
  pub_twist->publish(twist_msg);
}