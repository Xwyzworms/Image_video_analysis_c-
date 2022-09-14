#include <iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>


void colorReduce(cv::Mat image, int div = 64);
void colorReduceDereference(cv::Mat image, int div=64);
void colorReduceModulo(cv::Mat image, int div= 64);
void colorReduceBinaryMask(cv::Mat image, int div=64);
void colorReduceArtBinaryMask(cv::Mat image, int div=64);


void colorReduceTwo(const cv::Mat image, cv::Mat& result, int div = 64);
