#include "path_planning/goal_pose_publisher.hpp"

GoalPosePublisher::GoalPosePublisher() : Node("goal_pose_publisher")
{
  publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

  init_subscription_ = this->create_subscription<std_msgs::msg::String>("/publish_goal", 10, std::bind(&GoalPosePublisher::initial_pose_callback, this, std::placeholders::_1));

  amcl_subscription_ = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>("/amcl_pose", 10, std::bind(&GoalPosePublisher::amcl_pose_callback, this, std::placeholders::_1));
}

void GoalPosePublisher::initial_pose_callback(const std_msgs::msg::String::SharedPtr msg)
{
  (void)msg;

  if (!timer_)
  {
    timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&GoalPosePublisher::timer_callback, this));
  }
}

void GoalPosePublisher::timer_callback()
{
  auto message = geometry_msgs::msg::PoseStamped();
  message.header.stamp = this->get_clock()->now();
  message.header.frame_id = "map";
  message.pose.position.x = 2.0;
  message.pose.position.y = 0.5;
  message.pose.orientation.w = 1.0;
  publisher_->publish(message);
}

void GoalPosePublisher::amcl_pose_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
{
  if (!timer_)
    return;
  
  double x = msg->pose.pose.position.x - 2.0;
  double y = msg->pose.pose.position.y - 0.5;
  double distance = std::sqrt(x * x + y * y);

  if (distance < 0.5)
  {
    timer_->cancel();
    timer_.reset();
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GoalPosePublisher>());
  rclcpp::shutdown();
  return 0;
}