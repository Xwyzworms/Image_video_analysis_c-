#include "Pixels.h"

void addImageNoise(std::string path, int n) 
{
	cv::Mat image = cv::imread(path);

	int i, j;

	for (int k = 0; k < n; ++k) 
	{
		//Randomize 
		i = std::rand() % image.cols;
		j = std::rand() % image.rows;
		
		if (image.type() == CV_8UC1) 
		{
			// Do randomizze only for 1 channel
			// <uchar> return Reference
			image.at<uchar>(j, i) = 255;
		}
		else if(image.type() == CV_8UC3)
		{
			// Do randomize only for 3 channel
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;


		}
	}

	cv::imshow("Image noise", image);
	cv::waitKey(0);


}