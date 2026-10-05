# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target example_package::example_package
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${example_package_TARGETS}.
if(example_package_TARGETS AND NOT TARGET example_package::example_package)
  add_library(example_package::example_package INTERFACE IMPORTED)
  set_target_properties(example_package::example_package PROPERTIES
    INTERFACE_LINK_LIBRARIES "${example_package_TARGETS}")
endif()
