#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <algorithm>
#include <cmath>

class LidarObstacleAvoidance : public rclcpp::Node
{
public:
  LidarObstacleAvoidance() : Node("lidar_obstacle_avoidance")
  {
    // Create subscriber to LiDAR scan topic
    scan_subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "/scan", 10,
      std::bind(&LidarObstacleAvoidance::scan_callback, this, std::placeholders::_1));
    
    // Create publisher for velocity commands
    cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    
    // Parameters
    this->declare_parameter("safe_distance", 0.3);  // meters
    this->declare_parameter("max_linear_speed", 0.16);  // m/s
    this->declare_parameter("max_angular_speed", 2.84);  // rad/s
    
    safe_distance_ = this->get_parameter("safe_distance").as_double();
    max_linear_speed_ = this->get_parameter("max_linear_speed").as_double();
    max_angular_speed_ = this->get_parameter("max_angular_speed").as_double();
    
    RCLCPP_INFO(this->get_logger(), "LiDAR Obstacle Avoidance Node Started");
    RCLCPP_INFO(this->get_logger(), "Safe distance: %.2f m", safe_distance_);
  }

private:
  void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
  {
    // Analyze scan data
    float min_front_distance = std::numeric_limits<float>::max();
    float min_left_distance = std::numeric_limits<float>::max();
    float min_right_distance = std::numeric_limits<float>::max();
    
    size_t total_readings = msg->ranges.size();
    
    // TurtleBot3 LiDAR typically has 360 readings (0-359)
    // Index 0 = front, 90 = left, 180 = back, 270 = right
    // Front sector: indices around 0 (wrap around)
    // We'll check 90 degrees in front: 315-360 and 0-45
    
    size_t front_range = total_readings / 8;  // 45 degrees on each side = 90 total
    
    for (size_t i = 0; i < total_readings; i++)
    {
      float range = msg->ranges[i];
      
      // Skip invalid readings
      if (std::isinf(range) || std::isnan(range) || range < msg->range_min || range > msg->range_max)
        continue;
      
      // Front sector: last 45 degrees (315-360) and first 45 degrees (0-45)
      if (i <= front_range || i >= (total_readings - front_range))
      {
        min_front_distance = std::min(min_front_distance, range);
      }
      // Right sector: 270-315 degrees (right side)
      else if (i > (total_readings - front_range) && i < total_readings * 3 / 4)
      {
        min_right_distance = std::min(min_right_distance, range);
      }
      // Left sector: 45-90 degrees (left side)
      else if (i > front_range && i <= total_readings / 4)
      {
        min_left_distance = std::min(min_left_distance, range);
      }
      // Extended right sector: 180-270 degrees
      else if (i > total_readings / 4 && i < total_readings * 3 / 4)
      {
        min_right_distance = std::min(min_right_distance, range);
      }
      // Extended left sector: 90-180 degrees
      else
      {
        min_left_distance = std::min(min_left_distance, range);
      }
    }
    
    // Debug output to see what's being detected
    RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                         "Distances - Front: %.2f, Left: %.2f, Right: %.2f", 
                         min_front_distance, min_left_distance, min_right_distance);
    
    // Create velocity command based on obstacle distances
    auto twist_msg = geometry_msgs::msg::Twist();
    
    // Decision logic
    if (min_front_distance > safe_distance_)
    {
      // No obstacle ahead - move forward
      twist_msg.linear.x = max_linear_speed_;
      twist_msg.angular.z = 0.0;
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, 
                           "Moving forward (front: %.2f m)", min_front_distance);
    }
    else
    {
      // Obstacle ahead - decide which way to turn
      // Continue moving forward slowly while turning for smoother navigation
      twist_msg.linear.x = max_linear_speed_ * 0.2;
      
      if (min_left_distance > min_right_distance)
      {
        // Turn left
        twist_msg.angular.z = max_angular_speed_;
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500,
                           "Turning left (front: %.2f, left: %.2f, right: %.2f)", 
                           min_front_distance, min_left_distance, min_right_distance);
      }
      else
      {
        // Turn right
        twist_msg.angular.z = -max_angular_speed_;
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500,
                           "Turning right (front: %.2f, left: %.2f, right: %.2f)", 
                           min_front_distance, min_left_distance, min_right_distance);
      }
    }
    
    // Publish velocity command
    cmd_vel_publisher_->publish(twist_msg);
  }
  
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_subscription_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
  
  double safe_distance_;
  double max_linear_speed_;
  double max_angular_speed_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LidarObstacleAvoidance>());
  rclcpp::shutdown();
  return 0;
}