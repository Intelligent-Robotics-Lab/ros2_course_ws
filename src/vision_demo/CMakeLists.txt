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

add_executable(simple_aruco_detector src/simple_aruco_detector.cpp)

target_include_directories(simple_aruco_detector PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(simple_aruco_detector PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
ament_target_dependencies(
  simple_aruco_detector
  "rclcpp"
  "sensor_msgs"
  "geometry_msgs"
  "visualization_msgs"
  "cv_bridge"
  "image_transport"
  "std_msgs"
)

target_link_libraries(simple_aruco_detector
  ${OpenCV_LIBRARIES}
)
install(TARGETS simple_aruco_detector
  DESTINATION lib/${PROJECT_NAME})

  # Install files
install(DIRECTORY
  launch
  config
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
