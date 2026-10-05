// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from example_package:srv/Adder.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__STRUCT_H_
#define EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Adder in the package example_package.
typedef struct example_package__srv__Adder_Request
{
  double value1;
  double value2;
} example_package__srv__Adder_Request;

// Struct for a sequence of example_package__srv__Adder_Request.
typedef struct example_package__srv__Adder_Request__Sequence
{
  example_package__srv__Adder_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} example_package__srv__Adder_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Adder in the package example_package.
typedef struct example_package__srv__Adder_Response
{
  double result;
} example_package__srv__Adder_Response;

// Struct for a sequence of example_package__srv__Adder_Response.
typedef struct example_package__srv__Adder_Response__Sequence
{
  example_package__srv__Adder_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} example_package__srv__Adder_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EXAMPLE_PACKAGE__SRV__DETAIL__ADDER__STRUCT_H_
