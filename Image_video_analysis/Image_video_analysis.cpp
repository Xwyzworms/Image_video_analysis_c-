// Image_video_analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include "Mat_ds.h"
#include "Roi.h"
#include "Pixels.h"
#include "PointerImageScanner.h"



int main()
{
        
    //std::string image_path = "Test.jpg";

    //cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
    //cv::resize(image, image, { 500, 500 }, 0, 0, cv::INTER_NEAREST);

    //cv::imshow("image", image);
    //createDifferentMap();
    //readImage("puppy.bmp");
    //cv::Mat grey = createImage();
    //cv::imshow("Image Gery", grey);
    //cv::waitKey(0);

    // Read the Image in Gray Scale
    //cv::Mat image1 = cv::imread("puppy.bmp", cv::IMREAD_GRAYSCALE);
    //cv::Mat image2;
    //image1.convertTo(image2, CV_32F, 1 / 255, 0);

    //cv::imshow("ConvertedImage", image2);
    //cv::waitKey(0);
    
    //drawROIFromImage("puppy.bmp", "smalllogo.png");
    //cv::waitKey(0);

    //maskImage("puppy.bmp", "smalllogo.png");


    // ????
    //addImageNoise("puppy.bmp", 1000);
    cv::Mat img = cv::imread("puppy.bmp");
    cv::Mat temp;
    colorReduceTwo(img, temp, 63);


    return 0;
}
