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

  cv::Mat gray;
  cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
  std::cout << "Converted to Grayscale." << std::endl;
  
  cv::Mat hsv;
  cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
  std::cout << "Converted to HSV." << std::endl;
  
  std::vector<cv::Mat> hsv_channels;
  cv::split(hsv, hsv_channels);
  // hsv_channels[0] hue channel
  // hsv_channels[1] saturation channel
  //...
  std::cout << "Split into HSV channels (H, S, V)" << std::endl;
  
  cv::imshow("Original", img);
  cv::imshow("Grayscale", gray);
  cv::imshow("HSV", hsv);
  cv::imshow("Hue Channel", hsv_channels[0]);
  cv::imshow("Saturation Channel", hsv_channels[1]);
  cv::imshow("Value Channel", hsv_channels[2]);

  std::cout << "Press a key to close the window." << std::endl;
  cv::waitKey(0);
  cv::destroyAllWindows();

  return 0;
}