#include <opencv2/opencv.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <iostream>

int main()
{
    std::cout << "=== OpenCV Resize, Crop, and Rotate Demo ===" << std::endl;
    
    std::string package_path = ament_index_cpp::get_package_share_directory("opencv_examples");
    std::string image_path = package_path + "/images/robot.jpg";
    
    cv::Mat img = cv::imread(image_path);
    
    if (img.empty()) {
        std::cerr << "ERROR: Could not read image!" << std::endl;
        return 1;
    }
    
    // Resize - make it smaller
    cv::Mat resized;
    cv::resize(img, resized, cv::Size(320, 240));
    std::cout << "Resized to 320x240" << std::endl;
    
    // Resize - double the size
    cv::Mat enlarged;
    cv::resize(img, enlarged, cv::Size(), 2.0, 2.0);
    std::cout << "Enlarged by 2x" << std::endl;
    
    // Crop - extract center region
    int crop_width = img.cols / 2;
    int crop_height = img.rows / 2;
    int start_x = img.cols / 4;
    int start_y = img.rows / 4;
    cv::Rect roi(start_x, start_y, crop_width, crop_height);
    cv::Mat cropped = img(roi);
    std::cout << "Cropped center region" << std::endl;
    
    // Rotate 45 degrees
    cv::Point2f center(img.cols / 2.0, img.rows / 2.0);
    cv::Mat rot_mat = cv::getRotationMatrix2D(center, 45, 1.0);
    cv::Mat rotated;
    cv::warpAffine(img, rotated, rot_mat, img.size());
    std::cout << "Rotated 45 degrees" << std::endl;
    
    // Flip horizontally
    cv::Mat flipped;
    cv::flip(img, flipped, 1);
    std::cout << "Flipped horizontally" << std::endl;
    
    // Display all transformations
    cv::imshow("Original", img);
    cv::imshow("Resized (320x240)", resized);
    cv::imshow("Cropped", cropped);
    cv::imshow("Rotated 45°", rotated);
    cv::imshow("Flipped", flipped);
    
    std::cout << "Press any key to close all windows..." << std::endl;
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    return 0;
}
