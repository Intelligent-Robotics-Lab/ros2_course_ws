#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/header.hpp"

rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_string;
void stringCallback(const std_msgs::msg::String::SharedPtr msg);

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("topic_publisher");
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_string = node->create_subscription<std_msgs::msg::String>("topic_in", 1, stringCallback);
  pub_string = node->create_publisher<std_msgs::msg::String>("topic_out", 1);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void stringCallback(const std_msgs::msg::String::SharedPtr msg)
{
  std_msgs::msg::String new_string;
  new_string.data = msg->data + "_123";
  pub_string->publish(new_string);
}