cmake_minimum_required(VERSION 3.8)
project(example_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/Adder.srv"
)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} rosidl_typesupport_cpp)
ament_export_dependencies(rosidl_default_runtime)

add_executable(topic_publisher src/topic_publisher.cpp)
target_link_libraries(topic_publisher PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(service_advertiser src/service_advertiser.cpp)
target_link_libraries(service_advertiser PUBLIC rclcpp::rclcpp ${example_package_TARGETS} ${cpp_typesupport_target})

add_executable(service_client src/service_client.cpp)
target_link_libraries(service_client PUBLIC rclcpp::rclcpp ${example_package_TARGETS} ${cpp_typesupport_target})

add_executable(turtle_timer src/turtle_timer.cpp)
target_link_libraries(turtle_timer PUBLIC rclcpp::rclcpp ${geometry_msgs_TARGETS})

add_executable(turtle_subpub src/turtle_subpub.cpp)
target_link_libraries(turtle_subpub PUBLIC rclcpp::rclcpp ${turtlesim_TARGETS} ${geometry_msgs_TARGETS})

add_executable(turtle_speed src/turtle_speed.cpp)
target_link_libraries(turtle_speed PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} ${geometry_msgs_TARGETS})

add_executable(turtle_distance src/turtle_distance.cpp)
target_link_libraries(turtle_distance PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} ${turtlesim_TARGETS})

add_executable(namespaces src/namespaces.cpp)
target_link_libraries(namespaces PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
ament_target_dependencies( turtle_tf_broadcaster rclcpp geometry_msgs turtlesim tf2 tf2_ros)

install(TARGETS topic_publisher service_advertiser service_client turtle_timer turtle_subpub turtle_speed turtle_distance namespaces turtle_tf_broadcaster DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

ament_package()