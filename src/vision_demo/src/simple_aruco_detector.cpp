// ============================================================================
// SINGLE FILE VERSION - Everything in one place!
// src/simple_aruco_detector.cpp
// ============================================================================

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <std_msgs/msg/string.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <sstream>

// ============================================================================
// CLASS DEFINITION
// ============================================================================
class SimpleArucoDetector : public rclcpp::Node
{
public:
  SimpleArucoDetector() : Node("simple_aruco_detector"), camera_info_received_(false)
  {
    // Declare parameters
    this->declare_parameter<bool>("show_debug_image", true);
    this->declare_parameter<std::string>("camera_topic", "/camera/image_raw");
    this->declare_parameter<std::string>("camera_info_topic", "/camera/camera_info");
    
    // Get parameters
    show_debug_image_ = this->get_parameter("show_debug_image").as_bool();
    auto camera_topic = this->get_parameter("camera_topic").as_string();
    auto camera_info_topic = this->get_parameter("camera_info_topic").as_string();
    
    // Initialize Aruco dictionary
    aruco_dict_ = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    detector_params_ = cv::aruco::DetectorParameters::create();
    
    // Initialize camera matrices
    camera_matrix_ = cv::Mat::eye(3, 3, CV_64F);
    dist_coeffs_ = cv::Mat::zeros(5, 1, CV_64F);
    
    // Create subscribers
    image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
      camera_topic, 10,
      std::bind(&SimpleArucoDetector::imageCallback, this, std::placeholders::_1));
    
    camera_info_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
      camera_info_topic, 10,
      std::bind(&SimpleArucoDetector::cameraInfoCallback, this, std::placeholders::_1));
    
    // Create publishers
    detections_pub_ = this->create_publisher<std_msgs::msg::String>("aruco_detections", 10);
    
    if (show_debug_image_) {
      debug_image_pub_ = image_transport::create_publisher(this, "debug_image");
    }
    
    RCLCPP_INFO(this->get_logger(), "Simple Aruco Detector initialized");
    RCLCPP_INFO(this->get_logger(), "Drive around to detect Aruco markers!");
  }

private:
  // Camera info callback
  void cameraInfoCallback(const sensor_msgs::msg::CameraInfo::SharedPtr msg)
  {
    if (camera_info_received_) return;
    
    // Extract camera matrix
    camera_matrix_ = cv::Mat(3, 3, CV_64F);
    for (int i = 0; i < 9; i++) {
      camera_matrix_.at<double>(i / 3, i % 3) = msg->k[i];
    }
    
    // Extract distortion coefficients
    dist_coeffs_ = cv::Mat(msg->d.size(), 1, CV_64F);
    for (size_t i = 0; i < msg->d.size(); i++) {
      dist_coeffs_.at<double>(i, 0) = msg->d[i];
    }
    
    camera_info_received_ = true;
    RCLCPP_INFO(this->get_logger(), "Camera calibration received");
  }
  
  // Image callback - main processing
  void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
    // Convert ROS image to OpenCV
    cv_bridge::CvImagePtr cv_ptr;
    try {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception & e) {
      RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
      return;
    }
    
    // Detect markers
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f>> corners;
    cv::aruco::detectMarkers(cv_ptr->image, aruco_dict_, corners, ids, detector_params_);
    
    // If markers found, draw and publish
    if (!ids.empty()) {
      // Draw on image
      cv::aruco::drawDetectedMarkers(cv_ptr->image, corners, ids);
      
      // Create text summary
      std::stringstream ss;
      ss << "Detected " << ids.size() << " marker(s): ";
      for (size_t i = 0; i < ids.size(); i++) {
        ss << "ID" << ids[i];
        if (i < ids.size() - 1) ss << ", ";
      }
      
      // Add text to image
      cv::putText(cv_ptr->image, ss.str(), cv::Point(10, 30), 
                  cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 255, 0), 2);
      
      // Publish text message
      auto detection_msg = std_msgs::msg::String();
      detection_msg.data = ss.str();
      detections_pub_->publish(detection_msg);
      
      // Log to console
      RCLCPP_INFO(this->get_logger(), "%s", ss.str().c_str());
    }
    
    // Publish debug image
    if (show_debug_image_) {
      debug_image_pub_.publish(cv_ptr->toImageMsg());
    }
  }
  
  // Member variables
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
  rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;
  image_transport::Publisher debug_image_pub_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr detections_pub_;
  
  cv::Ptr<cv::aruco::Dictionary> aruco_dict_;
  cv::Ptr<cv::aruco::DetectorParameters> detector_params_;
  cv::Mat camera_matrix_;
  cv::Mat dist_coeffs_;
  bool camera_info_received_;
  bool show_debug_image_;
};

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleArucoDetector>();
  RCLCPP_INFO(node->get_logger(), "Starting Aruco Detector - Use teleop to drive!");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}