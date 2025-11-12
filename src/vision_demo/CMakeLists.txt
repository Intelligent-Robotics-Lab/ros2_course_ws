cmake_minimum_required(VERSION 3.8)
project(vision_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(std_msgs REQUIRED)

# Include directories
include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

# Aruco Shape Detector Node
add_executable(aruco_detector_node
  src/simple_aruco_detector.cpp
)

ament_target_dependencies(
  aruco_detector_node
  "rclcpp"
  "sensor_msgs"
  "geometry_msgs"
  "visualization_msgs"
  "cv_bridge"
  "image_transport"
  "std_msgs"
)

install(TARGETS aruco_detector_node
  DESTINATION lib/${PROJECT_NAME})

# Install files
install(DIRECTORY
  launch
  urdf
  worlds
  meshes
  materials
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
