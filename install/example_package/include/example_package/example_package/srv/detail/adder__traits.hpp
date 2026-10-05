// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from example_package:srv/Adder.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__TRAITS_HPP_
#define EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "example_package/srv/detail/adder__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace example_package
{

namespace srv
{

inline void to_flow_style_yaml(
  const Adder_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: value1
  {
    out << "value1: ";
    rosidl_generator_traits::value_to_yaml(msg.value1, out);
    out << ", ";
  }

  // member: value2
  {
    out << "value2: ";
    rosidl_generator_traits::value_to_yaml(msg.value2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Adder_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value1: ";
    rosidl_generator_traits::value_to_yaml(msg.value1, out);
    out << "\n";
  }

  // member: value2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value2: ";
    rosidl_generator_traits::value_to_yaml(msg.value2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Adder_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace example_package

namespace rosidl_generator_traits
{

[[deprecated("use example_package::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const example_package::srv::Adder_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  example_package::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use example_package::srv::to_yaml() instead")]]
inline std::string to_yaml(const example_package::srv::Adder_Request & msg)
{
  return example_package::srv::to_yaml(msg);
}

template<>
inline const char * data_type<example_package::srv::Adder_Request>()
{
  return "example_package::srv::Adder_Request";
}

template<>
inline const char * name<example_package::srv::Adder_Request>()
{
  return "example_package/srv/Adder_Request";
}

template<>
struct has_fixed_size<example_package::srv::Adder_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<example_package::srv::Adder_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<example_package::srv::Adder_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace example_package
{

namespace srv
{

inline void to_flow_style_yaml(
  const Adder_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Adder_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Adder_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace example_package

namespace rosidl_generator_traits
{

[[deprecated("use example_package::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const example_package::srv::Adder_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  example_package::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use example_package::srv::to_yaml() instead")]]
inline std::string to_yaml(const example_package::srv::Adder_Response & msg)
{
  return example_package::srv::to_yaml(msg);
}

template<>
inline const char * data_type<example_package::srv::Adder_Response>()
{
  return "example_package::srv::Adder_Response";
}

template<>
inline const char * name<example_package::srv::Adder_Response>()
{
  return "example_package/srv/Adder_Response";
}

template<>
struct has_fixed_size<example_package::srv::Adder_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<example_package::srv::Adder_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<example_package::srv::Adder_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<example_package::srv::Adder>()
{
  return "example_package::srv::Adder";
}

template<>
inline const char * name<example_package::srv::Adder>()
{
  return "example_package/srv/Adder";
}

template<>
struct has_fixed_size<example_package::srv::Adder>
  : std::integral_constant<
    bool,
    has_fixed_size<example_package::srv::Adder_Request>::value &&
    has_fixed_size<example_package::srv::Adder_Response>::value
  >
{
};

template<>
struct has_bounded_size<example_package::srv::Adder>
  : std::integral_constant<
    bool,
    has_bounded_size<example_package::srv::Adder_Request>::value &&
    has_bounded_size<example_package::srv::Adder_Response>::value
  >
{
};

template<>
struct is_service<example_package::srv::Adder>
  : std::true_type
{
};

template<>
struct is_service_request<example_package::srv::Adder_Request>
  : std::true_type
{
};

template<>
struct is_service_response<example_package::srv::Adder_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__TRAITS_HPP_
