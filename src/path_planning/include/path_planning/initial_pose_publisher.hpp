#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"

class InitialPosePublisher : public rclcpp::Node
{
  public:
    InitialPosePublisher();
  
  private:
    void timer_callback();

    rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};