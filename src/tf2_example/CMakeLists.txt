cmake_minimum_required(VERSION 3.8)
project(tf2_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(turtle_tf2_broadcasters src/turtle_tf2_broadcasters.cpp)
ament_target_dependencies(turtle_tf2_broadcasters
  "geometry_msgs"
  "rclcpp"
  "tf2"
  "tf2_ros"
  "turtlesim"
)
install(TARGETS turtle_tf2_broadcasters
  DESTINATION lib/${PROJECT_NAME})


add_executable(turtle_tf2_listener src/turtle_tf2_listener.cpp)
ament_target_dependencies(turtle_tf2_listener
  "geometry_msgs"
  "rclcpp"
  "tf2"
  "tf2_ros"
  "turtlesim"
)
install(TARGETS turtle_tf2_listener
  DESTINATION lib/${PROJECT_NAME})



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
