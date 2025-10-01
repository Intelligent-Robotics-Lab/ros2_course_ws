#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("namespace_publisher");

  auto pub_global = node->create_publisher<std_msgs::msg::String>("global", 1);
  auto pub_private = node->create_publisher<std_msgs::msg::String>("~/private", 1);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}