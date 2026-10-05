// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from example_package:srv/Adder.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__BUILDER_HPP_
#define EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "example_package/srv/detail/adder__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace example_package
{

namespace srv
{

namespace builder
{

class Init_Adder_Request_value2
{
public:
  explicit Init_Adder_Request_value2(::example_package::srv::Adder_Request & msg)
  : msg_(msg)
  {}
  ::example_package::srv::Adder_Request value2(::example_package::srv::Adder_Request::_value2_type arg)
  {
    msg_.value2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_package::srv::Adder_Request msg_;
};

class Init_Adder_Request_value1
{
public:
  Init_Adder_Request_value1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Adder_Request_value2 value1(::example_package::srv::Adder_Request::_value1_type arg)
  {
    msg_.value1 = std::move(arg);
    return Init_Adder_Request_value2(msg_);
  }

private:
  ::example_package::srv::Adder_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_package::srv::Adder_Request>()
{
  return example_package::srv::builder::Init_Adder_Request_value1();
}

}  // namespace example_package


namespace example_package
{

namespace srv
{

namespace builder
{

class Init_Adder_Response_result
{
public:
  Init_Adder_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::example_package::srv::Adder_Response result(::example_package::srv::Adder_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_package::srv::Adder_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_package::srv::Adder_Response>()
{
  return example_package::srv::builder::Init_Adder_Response_result();
}

}  // namespace example_package

#endif  // EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__BUILDER_HPP_
