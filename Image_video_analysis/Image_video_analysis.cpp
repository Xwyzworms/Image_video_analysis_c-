// Image_video_analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include "Mat_ds.h"

int main()
{
        
    //std::string image_path = "Test.jpg";

    //cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
    //cv::resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);

    //cv::imshow("image", image);




    createDifferentMap();
   



    cv::waitKey(0);
    return 0;
}
