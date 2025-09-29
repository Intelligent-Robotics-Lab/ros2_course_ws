#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "example_package/srv/adder.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("service_client");
  rclcpp::Client<example_package::srv::Adder>::SharedPtr client = node->create_client<example_package::srv::Adder>("adder_service");
  std::shared_ptr<example_package::srv::Adder::Request> request = std::make_shared<example_package::srv::Adder::Request>();
  request->val1 = 4.0;
  request->val2 = 13.0;
  // while(!client->wait_for_service(std::chrono::seconds(1)));
  rclcpp::Client<example_package::srv::Adder>::FutureAndRequestId response = client->async_send_request(request);
  rclcpp::FutureReturnCode success = rclcpp::spin_until_future_complete(node, response);
  if(success == rclcpp::FutureReturnCode::SUCCESS)
    RCLCPP_INFO(node->get_logger(), "Result: %lf", response.get()->result);
  else
    RCLCPP_ERROR(node->get_logger(), "Failed to call service adder_service");
  rclcpp::shutdown();
  return 0;
}