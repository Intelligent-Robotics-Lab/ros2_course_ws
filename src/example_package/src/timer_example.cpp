#include <memory>
#include <iostream>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"


rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_counter;
std_msgs::msg::Float64 counter;

void timerCallback();

int main(int argc, char** argv){
  rclcpp::init(argc,argv);
  auto node = rclcpp::Node::make_shared("timer_example");

  auto timer = node->create_wall_timer(std::chrono::milliseconds(1000),timerCallback);
  pub_counter = node->create_publisher<std_msgs::msg::Float64>("~/counter",1);
  counter.data = 0;

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void timerCallback(){
  counter.data = counter.data + 1;
  pub_counter->publish(counter);
}