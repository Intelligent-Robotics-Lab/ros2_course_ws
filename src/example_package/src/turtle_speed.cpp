#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"

rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pub_speed;
geometry_msgs::msg::PointStamped previous_point;
void pointCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg);

int main(int argc, char** argv)
{
  rclcpp::init(argc,argv);
  auto node = rclcpp::Node::make_shared("turtle_speed");

  auto sub_point = node->create_subscription<geometry_msgs::msg::PointStamped>("turtle1/point", 1, pointCallback);
  pub_speed = node->create_publisher<std_msgs::msg::Float64>("turtle1/speed", 1);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

void pointCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg)
{
  if (previous_point.header.stamp.sec != 0)
  {
    double distance = std::sqrt(std::pow(msg->point.x - previous_point.point.x, 2) + std::pow(msg->point.y - previous_point.point.y, 2));
    double time = (msg->header.stamp.sec + msg->header.stamp.nanosec * 1e-9) - (previous_point.header.stamp.sec + previous_point.header.stamp.nanosec * 1e-9);

    std_msgs::msg::Float64 speed_msg;
    speed_msg.data = distance / time;
    pub_speed->publish(speed_msg);
  }
  previous_point = *msg;
}