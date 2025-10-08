#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "turtlesim/msg/pose.hpp"

turtlesim::msg::Pose turtle1_pose;
turtlesim::msg::Pose turtle2_pose;
rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_distance;
void pose1Callback(const turtlesim::msg::Pose::SharedPtr msg);
void pose2Callback(const turtlesim::msg::Pose::SharedPtr msg);
void calculateDistance();

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("turtle_distance");

  node->declare_parameter<std::string>("turtle1_name", "turtle");
  node->declare_parameter<std::string>("turtle2_name", "turtle");

  auto sub_pose1 = node->create_subscription<turtlesim::msg::Pose>(node->get_parameter("turtle1_name").as_string() + "/pose", 1, pose1Callback);
  auto sub_pose2 = node->create_subscription<turtlesim::msg::Pose>(node->get_parameter("turtle2_name").as_string() + "/pose", 1, pose2Callback);

  pub_distance = node->create_publisher<std_msgs::msg::Float64>("~/distance", 1);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void pose1Callback(const turtlesim::msg::Pose::SharedPtr msg)
{
  turtle1_pose = *msg;
  calculateDistance();
}

void pose2Callback(const turtlesim::msg::Pose::SharedPtr msg)
{
  turtle2_pose = *msg;
  calculateDistance();
}

void calculateDistance()
{
  std_msgs::msg::Float64 distance_msg;
  distance_msg.data = std::sqrt(std::pow(turtle1_pose.x - turtle2_pose.x, 2) + std::pow(turtle1_pose.y - turtle2_pose.y, 2));
  pub_distance->publish(distance_msg);
}