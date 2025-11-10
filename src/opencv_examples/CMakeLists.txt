cmake_minimum_required(VERSION 3.8)
project(opencv_examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
find_package(ament_index_cpp REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

#include Excecutable 1: Read and Display
add_executable(read_display src/read_display.cpp)
target_link_libraries(read_display ${OpenCV_LIBS})
ament_target_dependencies(read_display ament_index_cpp)

#include Excecutable 2: Read and Convert Colors
add_executable(color_convert src/color_convert.cpp)
target_link_libraries(color_convert ${OpenCV_LIBS})
ament_target_dependencies(color_convert ament_index_cpp)

# Executable 3: Resize, Crop, Rotate
add_executable(resize_crop_rotate src/resize_crop_rotate.cpp)
target_link_libraries(resize_crop_rotate ${OpenCV_LIBS})
ament_target_dependencies(resize_crop_rotate ament_index_cpp)

#include Excecutable 4
add_executable(draw_shapes src/draw_shapes.cpp)
target_link_libraries(draw_shapes ${OpenCV_LIBS})
ament_target_dependencies(draw_shapes ament_index_cpp)

# Executable 5: Blur and Smoothing
add_executable(blur_smooth src/blur_smooth.cpp)
target_link_libraries(blur_smooth ${OpenCV_LIBS})
ament_target_dependencies(blur_smooth ament_index_cpp)

install(TARGETS
read_display
color_convert
resize_crop_rotate
draw_shapes
blur_smooth
DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY 
  images/
  DESTINATION share/${PROJECT_NAME}/images
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
