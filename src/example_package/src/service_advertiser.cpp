#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "example_package/srv/adder.hpp"

bool srvCallback(
  const std::shared_ptr<example_package::srv::Adder::Request> req,
  std::shared_ptr<example_package::srv::Adder::Response> res);

int main(int argc, char** argv){
  rclcpp::init(argc, argv);
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("service_advertiser");

  rclcpp::Service<example_package::srv::Adder>::SharedPtr srv = node->create_service<example_package::srv::Adder>("adder_service", srvCallback);
  
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}


bool srvCallback(
  const std::shared_ptr<example_package::srv::Adder::Request> req,
  std::shared_ptr<example_package::srv::Adder::Response> res){
    res->result = req->value1 + req->value2;
    return true;
  }
  