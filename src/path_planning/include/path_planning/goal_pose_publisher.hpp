#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"

class GoalPosePublisher : public rclcpp::Node
{
  public:
    GoalPosePublisher();

  private:
    void initial_pose_callback(const std_msgs::msg::String::SharedPtr msg);
    void timer_callback();
    void amcl_pose_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);

    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr init_subscription_;
    rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr amcl_subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
};