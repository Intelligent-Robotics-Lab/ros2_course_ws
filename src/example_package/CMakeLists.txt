cmake_minimum_required(VERSION 3.8)
project(example_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/Adder.srv"
)

rosidl_get_typesupport_target(cpp_typesupport_target 
  ${PROJECT_NAME} rosidl_typesupport_cpp
)

ament_export_dependencies(rosidl_default_runtime)


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

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

#Setting up topic publisher executable
add_executable(topic_publisher src/topic_publisher.cpp)
target_link_libraries(topic_publisher PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})
install(TARGETS topic_publisher DESTINATION lib/${PROJECT_NAME})

#Setting up service advertiser executable
add_executable(service_advertiser src/service_advertiser.cpp)
target_link_libraries(service_advertiser PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} "${cpp_typesupport_target}")
install(TARGETS service_advertiser DESTINATION lib/${PROJECT_NAME})

#Setting up service client executable
add_executable(service_client src/service_client.cpp)
target_link_libraries(service_client PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} "${cpp_typesupport_target}")
install(TARGETS service_client DESTINATION lib/${PROJECT_NAME})

#Setting up timer example executable
add_executable(timer_example src/timer_example.cpp)
target_link_libraries(timer_example PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} ${example_interfaces_TARGETS} "${cpp_typesupport_target}")
install(TARGETS timer_example DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

ament_package()
