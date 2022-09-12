#include "Mat_ds.h"

cv::Mat createImage() 
{
	cv::Mat img(500, 500, CV_8U, 50);

	return img;
}

void createDifferentMap()
{    
	/*
	cv::namedWindow("Image 1");
    cv::namedWindow("Image 2");
	cv::namedWindow("Image 3");
    cv::namedWindow("Image 4");
    cv::namedWindow("Image 5");
	cv::namedWindow("Image 6");
	*/
	cv::Mat image1(240, 320, CV_8U, 100);
	cv::imshow("Image", image1);
	cv::waitKey(0);

	// Reallocate image
	image1.create(120, 160, CV_8U);
	cv::waitKey(0);

	// Create A Red Color Image
	// Channel Color BGR
	cv::Mat image2(240, 320, CV_8UC3, cv::Scalar(0,0, 255));
	cv::imshow("Image", image2);
	cv::waitKey(0);
}

cv::Mat readImage(std::string path) 
{
	cv::Mat image =  cv::imread(path);
	cv::Mat image2;
	cv::Mat image3;
	// Here is Reading Same data block
	cv::Mat image4(image);
	cv::Mat image5 = image;

	// Here's Clone ( mean different Memory block)
	image.copyTo(image2);

	cv::Mat image5 = image3.clone();

	cv::imshow();
}
