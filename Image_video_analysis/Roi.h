#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

cv::Mat drawROIFromImage(std::string pathImage, std::string pathLogo);
void maskImage(std::string pathimage, std::string pathLogo);
