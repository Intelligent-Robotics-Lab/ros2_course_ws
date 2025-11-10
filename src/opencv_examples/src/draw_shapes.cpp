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

  cv::Mat canvas = img.clone();

  cv::rectangle(canvas, 
  cv::Point(50,50), cv::Point(200,200),
  cv::Scalar(0, 255, 0), 3);

  
  cv::imshow("Original", img);
  cv::imshow("Canvas", canvas);

  std::cout << "Press a key to close the window." << std::endl;
  cv::waitKey(0);
  cv::destroyAllWindows();

  return 0;
}