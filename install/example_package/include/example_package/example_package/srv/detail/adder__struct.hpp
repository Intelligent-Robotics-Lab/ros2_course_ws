// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from example_package:srv/Adder.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__STRUCT_HPP_
#define EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__example_package__srv__Adder_Request __attribute__((deprecated))
#else
# define DEPRECATED__example_package__srv__Adder_Request __declspec(deprecated)
#endif

namespace example_package
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Adder_Request_
{
  using Type = Adder_Request_<ContainerAllocator>;

  explicit Adder_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value1 = 0.0;
      this->value2 = 0.0;
    }
  }

  explicit Adder_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value1 = 0.0;
      this->value2 = 0.0;
    }
  }

  // field types and members
  using _value1_type =
    double;
  _value1_type value1;
  using _value2_type =
    double;
  _value2_type value2;

  // setters for named parameter idiom
  Type & set__value1(
    const double & _arg)
  {
    this->value1 = _arg;
    return *this;
  }
  Type & set__value2(
    const double & _arg)
  {
    this->value2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    example_package::srv::Adder_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const example_package::srv::Adder_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<example_package::srv::Adder_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<example_package::srv::Adder_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      example_package::srv::Adder_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<example_package::srv::Adder_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      example_package::srv::Adder_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<example_package::srv::Adder_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<example_package::srv::Adder_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<example_package::srv::Adder_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__example_package__srv__Adder_Request
    std::shared_ptr<example_package::srv::Adder_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__example_package__srv__Adder_Request
    std::shared_ptr<example_package::srv::Adder_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Adder_Request_ & other) const
  {
    if (this->value1 != other.value1) {
      return false;
    }
    if (this->value2 != other.value2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Adder_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Adder_Request_

// alias to use template instance with default allocator
using Adder_Request =
  example_package::srv::Adder_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace example_package


#ifndef _WIN32
# define DEPRECATED__example_package__srv__Adder_Response __attribute__((deprecated))
#else
# define DEPRECATED__example_package__srv__Adder_Response __declspec(deprecated)
#endif

namespace example_package
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Adder_Response_
{
  using Type = Adder_Response_<ContainerAllocator>;

  explicit Adder_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0.0;
    }
  }

  explicit Adder_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0.0;
    }
  }

  // field types and members
  using _result_type =
    double;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const double & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    example_package::srv::Adder_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const example_package::srv::Adder_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<example_package::srv::Adder_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<example_package::srv::Adder_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      example_package::srv::Adder_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<example_package::srv::Adder_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      example_package::srv::Adder_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<example_package::srv::Adder_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<example_package::srv::Adder_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<example_package::srv::Adder_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__example_package__srv__Adder_Response
    std::shared_ptr<example_package::srv::Adder_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__example_package__srv__Adder_Response
    std::shared_ptr<example_package::srv::Adder_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Adder_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Adder_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Adder_Response_

// alias to use template instance with default allocator
using Adder_Response =
  example_package::srv::Adder_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace example_package

namespace example_package
{

namespace srv
{

struct Adder
{
  using Request = example_package::srv::Adder_Request;
  using Response = example_package::srv::Adder_Response;
};

}  // namespace srv

}  // namespace example_package

#endif  // EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__STRUCT_HPP_
