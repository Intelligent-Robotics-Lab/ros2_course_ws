#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/logging.hpp"
#include "visualization_msgs/msg/marker.hpp"

int main(int argc, char**argv){
  rclcpp::init(argc,argv);

  auto node = rclcpp::Node::make_shared("marker_example");
  auto marker_pub = node->create_publisher<visualization_msgs::msg::Marker>
                                            ("visualization_markers", 1);

  uint32_t shape = visualization_msgs::msg::Marker::CUBE;

  while(rclcpp::ok()){
    visualization_msgs::msg::Marker marker;
    marker.header.frame_id = "frame2";
    marker.header.stamp = rclcpp::Clock().now();
    
    marker.ns = "marker_example";
    marker.id = 0;
    marker.type = shape;

    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0;
    marker.pose.orientation.y = 0;
    marker.pose.orientation.z = 0;
    marker.pose.orientation.w = 1;

    marker.scale.x = 1;
    marker.scale.y = 1;
    marker.scale.z = 1;
    
    marker.color.r = 0;
    marker.color.g = 1;
    marker.color.b = 0;
    marker.color.a = 1;

    marker.lifetime = rclcpp::Duration::from_nanoseconds(0);
    marker_pub->publish(marker);
  }

}