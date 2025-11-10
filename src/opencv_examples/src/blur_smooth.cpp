#include <opencv2/opencv.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <iostream>

int main()
{
    std::cout << "=== OpenCV Blur and Smoothing Demo ===" << std::endl;
    
    std::string package_path = ament_index_cpp::get_package_share_directory("opencv_examples");
    std::string image_path = package_path + "/images/robot.jpg";
    
    cv::Mat img = cv::imread(image_path);
    
    if (img.empty()) {
        std::cerr << "ERROR: Could not read image!" << std::endl;
        return 1;
    }
    
    // Simple averaging blur
    cv::Mat blur_avg;
    cv::blur(img, blur_avg, cv::Size(9, 9));
    std::cout << "Applied averaging blur (9x9)" << std::endl;
    
    // Gaussian blur
    cv::Mat blur_gauss;
    cv::GaussianBlur(img, blur_gauss, cv::Size(9, 9), 0);
    std::cout << "Applied Gaussian blur (9x9)" << std::endl;
    
    // Median blur (good for salt-and-pepper noise)
    cv::Mat blur_median;
    cv::medianBlur(img, blur_median, 9);
    std::cout << "Applied median blur (9x9)" << std::endl;
    
    // Bilateral filter (preserves edges)
    cv::Mat blur_bilateral;
    cv::bilateralFilter(img, blur_bilateral, 9, 75, 75);
    std::cout << "Applied bilateral filter" << std::endl;
    
    // Display all
    cv::imshow("Original", img);
    cv::imshow("Averaging Blur", blur_avg);
    cv::imshow("Gaussian Blur", blur_gauss);
    cv::imshow("Median Blur", blur_median);
    cv::imshow("Bilateral Filter", blur_bilateral);
    
    std::cout << "Press any key to close all windows..." << std::endl;
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    return 0;
}
