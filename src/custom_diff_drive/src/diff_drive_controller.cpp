#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64.hpp"

/**
 * DiffDriveController Class
 * 
 * This educational node demonstrates the mathematics behind differential drive kinematics.
 * It subscribes to velocity commands and calculates the individual wheel velocities
 * that would be needed to achieve the desired robot motion.
 * 
 * NOTE: This node does NOT actually control the robot. The Gazebo diff_drive plugin
 * handles the actual control. This node exists purely to show students the calculations
 * that happen inside the plugin.
 * 
 * Differential Drive Kinematics:
 * ------------------------------
 * A differential drive robot has two independently controlled wheels. To move the robot,
 * we need to calculate how fast each wheel should spin based on:
 *   - Desired linear velocity (forward/backward speed)
 *   - Desired angular velocity (turning rate)
 * 
 * The key equations are:
 *   v_left  = (v - omega * (L/2)) / r
 *   v_right = (v + omega * (L/2)) / r
 * 
 * Where:
 *   v       = linear velocity of robot center (m/s)
 *   omega   = angular velocity of robot (rad/s)
 *   L       = distance between wheels (wheel separation) (m)
 *   r       = radius of each wheel (m)
 *   v_left  = left wheel angular velocity (rad/s)
 *   v_right = right wheel angular velocity (rad/s)
 */
class DiffDriveController : public rclcpp::Node
{
public:
  DiffDriveController() : Node("diff_drive_controller")
  {
    // Declare and get parameters for robot physical dimensions
    // These values should match your robot's actual measurements
    wheel_separation_ = this->declare_parameter("wheel_separation", 0.160);  // meters (distance between wheels)
    wheel_radius_     = this->declare_parameter("wheel_radius", 0.033);      // meters (wheel radius)
    
    // Subscribe to the cmd_vel topic to receive velocity commands
    // This is the same topic that teleop_twist_keyboard publishes to
    // and that the Gazebo diff_drive plugin subscribes to
    cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel", 10,
      std::bind(&DiffDriveController::cmdVelCallback, this, std::placeholders::_1));
    
    // Print startup information
    RCLCPP_INFO(this->get_logger(), "========================================");
    RCLCPP_INFO(this->get_logger(), "Custom DiffDrive Controller (Educational Demo)");
    RCLCPP_INFO(this->get_logger(), "========================================");
    RCLCPP_INFO(this->get_logger(), "Robot Parameters:");
    RCLCPP_INFO(this->get_logger(), "  Wheel separation: %.3f m", wheel_separation_);
    RCLCPP_INFO(this->get_logger(), "  Wheel radius: %.3f m", wheel_radius_);
    RCLCPP_INFO(this->get_logger(), " ");
    RCLCPP_INFO(this->get_logger(), "Purpose:");
    RCLCPP_INFO(this->get_logger(), "  This node demonstrates differential drive kinematics.");
    RCLCPP_INFO(this->get_logger(), "  It shows the calculations that the Gazebo plugin");
    RCLCPP_INFO(this->get_logger(), "  performs internally to control the robot.");
    RCLCPP_INFO(this->get_logger(), "========================================");
    RCLCPP_INFO(this->get_logger(), " ");
  }

private:
  /**
   * Callback function that executes whenever a new cmd_vel message arrives
   * 
   * This function:
   * 1. Extracts linear and angular velocities from the incoming message
   * 2. Applies differential drive kinematics to calculate wheel velocities
   * 3. Prints detailed information about the calculations
   * 
   * @param msg Shared pointer to the incoming Twist message containing velocity commands
   */
  void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    // Extract velocities from the message
    // linear.x is forward/backward velocity in m/s (positive = forward)
    double v = msg->linear.x;
    
    // angular.z is turning velocity in rad/s (positive = counter-clockwise)
    double omega = msg->angular.z;
    
    // Apply differential drive kinematics
    // 
    // Intuition behind the formulas:
    // - When turning, the inner wheel moves slower and outer wheel moves faster
    // - The term (omega * wheel_separation / 2) represents the velocity difference
    //   caused by rotation
    // - We subtract this from v for the left wheel and add it for the right wheel
    // - Finally, we divide by wheel radius to convert from linear velocity (m/s)
    //   to angular velocity (rad/s)
    
    double v_left  = (v - omega * (wheel_separation_ / 2.0)) / wheel_radius_;
    double v_right = (v + omega * (wheel_separation_ / 2.0)) / wheel_radius_;
    
    // Print detailed calculation information
    RCLCPP_INFO(this->get_logger(), "================================================");
    RCLCPP_INFO(this->get_logger(), "Received cmd_vel command:");
    RCLCPP_INFO(this->get_logger(), "  Linear velocity  (v):     %+.3f m/s", v);
    RCLCPP_INFO(this->get_logger(), "  Angular velocity (omega): %+.3f rad/s", omega);
    RCLCPP_INFO(this->get_logger(), " ");
    RCLCPP_INFO(this->get_logger(), "Applying differential drive kinematics:");
    RCLCPP_INFO(this->get_logger(), " ");
    RCLCPP_INFO(this->get_logger(), "  Left wheel calculation:");
    RCLCPP_INFO(this->get_logger(), "    v_left = (v - omega * L/2) / r");
    RCLCPP_INFO(this->get_logger(), "    v_left = (%.3f - %.3f * %.3f/2) / %.3f", 
                v, omega, wheel_separation_, wheel_radius_);
    RCLCPP_INFO(this->get_logger(), "    v_left = %.3f rad/s", v_left);
    RCLCPP_INFO(this->get_logger(), " ");
    RCLCPP_INFO(this->get_logger(), "  Right wheel calculation:");
    RCLCPP_INFO(this->get_logger(), "    v_right = (v + omega * L/2) / r");
    RCLCPP_INFO(this->get_logger(), "    v_right = (%.3f + %.3f * %.3f/2) / %.3f", 
                v, omega, wheel_separation_, wheel_radius_);
    RCLCPP_INFO(this->get_logger(), "    v_right = %.3f rad/s", v_right);
    RCLCPP_INFO(this->get_logger(), " ");
    RCLCPP_INFO(this->get_logger(), "Result:");
    RCLCPP_INFO(this->get_logger(), "  Left wheel velocity:  %+.3f rad/s", v_left);
    RCLCPP_INFO(this->get_logger(), "  Right wheel velocity: %+.3f rad/s", v_right);
    RCLCPP_INFO(this->get_logger(), "================================================");
    RCLCPP_INFO(this->get_logger(), " ");
  }

  // Robot physical parameters (in meters)
  double wheel_separation_;  // Distance between the two wheels
  double wheel_radius_;      // Radius of each wheel
  
  // ROS 2 subscriber for velocity commands
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
};

/**
 * Main function
 * 
 * This is the entry point of the program. It:
 * 1. Initializes the ROS 2 system
 * 2. Creates an instance of our DiffDriveController node
 * 3. Spins (runs) the node to process callbacks
 * 4. Cleans up when the program exits
 */
int main(int argc, char **argv)
{
  // Initialize ROS 2
  rclcpp::init(argc, argv);
  
  // Create and run the node
  // The node will continue running until Ctrl+C is pressed
  rclcpp::spin(std::make_shared<DiffDriveController>());
  
  // Cleanup ROS 2
  rclcpp::shutdown();
  
  return 0;
}