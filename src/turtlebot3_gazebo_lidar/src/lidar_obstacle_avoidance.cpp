#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <algorithm>
#include <cmath>
#include <limits>

class LidarObstacleAvoidance : public rclcpp::Node{
  public:
    LidarObstacleAvoidance() : Node("lidar_obstacle_avoidance"){
      //Suscribe to the LIDAR scan topic
      scan_subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/scan", 10, std::bind(&LidarObstacleAvoidance::scan_callback, this, std::placeholders::_1)
      );
      //Create publisher for cmd_vel topic
      cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
      //Parameters
      this->declare_parameter("Safe_Distance", 0.3); //meters
      this->declare_parameter("max_linear_speed", 0.16); //meters per second
      this->declare_parameter("max_angular_speed", 2.84); //radians per second

      safe_distance_ = this->get_parameter("Safe_Distance").as_double();
      max_linear_speed_ = this->get_parameter("max_linear_speed").as_double();
      max_angular_speed_ = this->get_parameter("max_angular_speed").as_double();

      //Log info
      RCLCPP_INFO(this->get_logger(), "LiDAR Obstacle Avoidance NODE has been started.");
      // RCLPCPP_INFO(this->get_logger(), "
    }

  private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg){
      //Analyze scan data from the lidar and determine if there are obstacles in front of the robot
      
      float min_front_distance = std::numeric_limits<float>::max();
      float min_left_distance = std::numeric_limits<float>::max();
      float min_right_distance = std::numeric_limits<float>::max();

      size_t total_readings = msg->ranges.size();

      // TurtleBot3 LiDAR typically has 360 readings (0-359)
      // Index 0 = front, 90 = left, 180 = back, 270 = right
      // Front sector: indices around 0 (wrap around)
      // We'll check 90 degrees in front: 315-360 and 0-45

      size_t front_range = total_readings/8; //45 degrees on each side = 90 (45 x 2)
      //Control Flow

      for (size_t i = 0; i<total_readings; i++){

        float range = msg->ranges[i];
        //skip invalid readings
        if (std::isinf(range) || std::isnan(range) || range < msg->range_min || range > msg-> range_max)
          continue;
        //front sector ( last 45 degrees (315-360) and the first 45 degrees (0-45))
        if (i <= front_range || i >= (total_readings - front_range)){
          min_front_distance = std::min(min_front_distance, range);
        }
        //left sector (45 - 180)
        else if ( i < total_readings/2){
          min_left_distance = std::min(min_left_distance, range);
        }
        //right sector (180-315)
        else{
          min_right_distance = std::min(min_right_distance, range);
        }

      }

      //debug output for what is being detected

      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Distances - front: %.2f, left: %.2f, Right: %.2f",
       min_front_distance, min_left_distance, min_right_distance);

      //create velocity message based on the obstacle distances
      auto twist_msg = geometry_msgs::msg::Twist();

      //Descision logic / control logic

      if (min_front_distance > safe_distance_){
        //If any obstacle its still far enough that its safe (> safe distance)
        twist_msg.linear.x = max_linear_speed_;
        twist_msg.angular.z = 0.0;
        RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Moving Forward (front: %.2f)",
        min_front_distance);
      }
      else {
        // Obstacle ahead of us - decide which way to turn
        // continue moving forward but slowly while we turn towards a better direction
        twist_msg.linear.x = max_linear_speed_ * 0.2;
        
        if (min_left_distance > min_right_distance){
          //turn left
          twist_msg.angular.z = max_angular_speed_;
          RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, "Distances - front: %.2f, left: %.2f, Right: %.2f",
          min_front_distance, min_left_distance, min_right_distance);

        }
        else {
          //turn right
          twist_msg.angular.z = -max_angular_speed_;
          RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 500, "Distances - front: %.2f, left: %.2f, Right: %.2f",
          min_front_distance, min_left_distance, min_right_distance);
        }
      }
      //Publish cmd_vel message
      cmd_vel_publisher_->publish(twist_msg);
    }
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;

    double safe_distance_;
    double max_linear_speed_;
    double max_angular_speed_;
};

int main (int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LidarObstacleAvoidance>());
  rclcpp::shutdown();
  return 0;
}