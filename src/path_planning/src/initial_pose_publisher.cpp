#include "path_planning/initial_pose_publisher.hpp"
#include "std_msgs/msg/string.hpp"

InitialPosePublisher::InitialPosePublisher() : Node("initial_pose_publisher")
{
  publisher_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("initialpose", 10);
  timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&InitialPosePublisher::timer_callback, this));
}

void InitialPosePublisher::timer_callback()
{
  if (publisher_->get_subscription_count() > 0)
  {
    timer_->cancel();

    auto message = geometry_msgs::msg::PoseWithCovarianceStamped();
    message.header.stamp = this->now();
    message.header.frame_id = "map";
    message.pose.pose.position.x = -2.0;
    message.pose.pose.position.y = -0.5;
    message.pose.pose.orientation.w = 1.0;

    publisher_->publish(message);
    auto goal_publisher = this->create_publisher<std_msgs::msg::String>("publish_goal", 10);
    auto goal_msg = std_msgs::msg::String();
    goal_msg.data = "go_to_goal";
    goal_publisher->publish(goal_msg);
    rclcpp::shutdown();
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<InitialPosePublisher>());
  rclcpp::shutdown();
  return 0;
}