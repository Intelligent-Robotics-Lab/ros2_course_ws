// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from example_package:srv/Adder.idl
// generated code does not contain a copyright notice
#include "example_package/srv/detail/adder__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
example_package__srv__Adder_Request__init(example_package__srv__Adder_Request * msg)
{
  if (!msg) {
    return false;
  }
  // value1
  // value2
  return true;
}

void
example_package__srv__Adder_Request__fini(example_package__srv__Adder_Request * msg)
{
  if (!msg) {
    return;
  }
  // value1
  // value2
}

bool
example_package__srv__Adder_Request__are_equal(const example_package__srv__Adder_Request * lhs, const example_package__srv__Adder_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // value1
  if (lhs->value1 != rhs->value1) {
    return false;
  }
  // value2
  if (lhs->value2 != rhs->value2) {
    return false;
  }
  return true;
}

bool
example_package__srv__Adder_Request__copy(
  const example_package__srv__Adder_Request * input,
  example_package__srv__Adder_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // value1
  output->value1 = input->value1;
  // value2
  output->value2 = input->value2;
  return true;
}

example_package__srv__Adder_Request *
example_package__srv__Adder_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  example_package__srv__Adder_Request * msg = (example_package__srv__Adder_Request *)allocator.allocate(sizeof(example_package__srv__Adder_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(example_package__srv__Adder_Request));
  bool success = example_package__srv__Adder_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
example_package__srv__Adder_Request__destroy(example_package__srv__Adder_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    example_package__srv__Adder_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
example_package__srv__Adder_Request__Sequence__init(example_package__srv__Adder_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  example_package__srv__Adder_Request * data = NULL;

  if (size) {
    data = (example_package__srv__Adder_Request *)allocator.zero_allocate(size, sizeof(example_package__srv__Adder_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = example_package__srv__Adder_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        example_package__srv__Adder_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
example_package__srv__Adder_Request__Sequence__fini(example_package__srv__Adder_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      example_package__srv__Adder_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

example_package__srv__Adder_Request__Sequence *
example_package__srv__Adder_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  example_package__srv__Adder_Request__Sequence * array = (example_package__srv__Adder_Request__Sequence *)allocator.allocate(sizeof(example_package__srv__Adder_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = example_package__srv__Adder_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
example_package__srv__Adder_Request__Sequence__destroy(example_package__srv__Adder_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    example_package__srv__Adder_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
example_package__srv__Adder_Request__Sequence__are_equal(const example_package__srv__Adder_Request__Sequence * lhs, const example_package__srv__Adder_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!example_package__srv__Adder_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
example_package__srv__Adder_Request__Sequence__copy(
  const example_package__srv__Adder_Request__Sequence * input,
  example_package__srv__Adder_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(example_package__srv__Adder_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    example_package__srv__Adder_Request * data =
      (example_package__srv__Adder_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!example_package__srv__Adder_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          example_package__srv__Adder_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!example_package__srv__Adder_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
example_package__srv__Adder_Response__init(example_package__srv__Adder_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
example_package__srv__Adder_Response__fini(example_package__srv__Adder_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
example_package__srv__Adder_Response__are_equal(const example_package__srv__Adder_Response * lhs, const example_package__srv__Adder_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
example_package__srv__Adder_Response__copy(
  const example_package__srv__Adder_Response * input,
  example_package__srv__Adder_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

example_package__srv__Adder_Response *
example_package__srv__Adder_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  example_package__srv__Adder_Response * msg = (example_package__srv__Adder_Response *)allocator.allocate(sizeof(example_package__srv__Adder_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(example_package__srv__Adder_Response));
  bool success = example_package__srv__Adder_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
example_package__srv__Adder_Response__destroy(example_package__srv__Adder_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    example_package__srv__Adder_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
example_package__srv__Adder_Response__Sequence__init(example_package__srv__Adder_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  example_package__srv__Adder_Response * data = NULL;

  if (size) {
    data = (example_package__srv__Adder_Response *)allocator.zero_allocate(size, sizeof(example_package__srv__Adder_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = example_package__srv__Adder_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        example_package__srv__Adder_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
example_package__srv__Adder_Response__Sequence__fini(example_package__srv__Adder_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      example_package__srv__Adder_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

example_package__srv__Adder_Response__Sequence *
example_package__srv__Adder_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  example_package__srv__Adder_Response__Sequence * array = (example_package__srv__Adder_Response__Sequence *)allocator.allocate(sizeof(example_package__srv__Adder_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = example_package__srv__Adder_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
example_package__srv__Adder_Response__Sequence__destroy(example_package__srv__Adder_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    example_package__srv__Adder_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
example_package__srv__Adder_Response__Sequence__are_equal(const example_package__srv__Adder_Response__Sequence * lhs, const example_package__srv__Adder_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!example_package__srv__Adder_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
example_package__srv__Adder_Response__Sequence__copy(
  const example_package__srv__Adder_Response__Sequence * input,
  example_package__srv__Adder_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(example_package__srv__Adder_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    example_package__srv__Adder_Response * data =
      (example_package__srv__Adder_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!example_package__srv__Adder_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          example_package__srv__Adder_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!example_package__srv__Adder_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
