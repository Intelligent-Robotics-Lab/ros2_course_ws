#include <opencv2/opencv.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <iostream>

int main(){
  std::cout << "=== OpenCV Read and Display Demo ===";
  std::string package_path = ament_index_cpp::get_package_share_directory("opencv_examples");

  std::string image_path = package_path + "/images/robot.jpg";

  std::cout << "Loading image from: " << image_path << std::endl;

  cv::Mat img = cv::imread(image_path);

  if (img.empty()){
    return 1;
  }

  std::cout << "Image Loaded!" << std::endl;

  std::cout << "Width:" << img.cols << " pixels" << std::endl;
  std::cout << "Height:" << img.rows << " pixels" << std::endl;

  std::cout << "Channels:" << img.channels() << std::endl;
  
  cv::imshow("Original", img);

  std::cout << "Press a key to close the window." << std::endl;
  cv::waitKey(0);
  cv::destroyAllWindows();

  return 0;
}