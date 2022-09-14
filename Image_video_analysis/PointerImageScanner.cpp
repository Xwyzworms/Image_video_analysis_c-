#include "PointerImageScanner.h"

void colorReduce(cv::Mat image, int div) 
{
	int nl = image.rows;
	int nc = image.cols * image.channels();
	for (int j = 0; j < nl; j++) 
	{
		// Get Adress of row j
		uchar* data = image.ptr<uchar>(j);
		for (int k = 0; k < nc; k++)
		{
			data[k] = (data[k] / div) * div + div / 2;

		}
	}
	cv::imshow("image", image);
	cv::waitKey(0);
}

void colorReduceTwo(const cv::Mat image, cv::Mat& result, int div) 
{
	result.create(image.rows, image.cols, image.type());

	int nl = image.rows;
	int nc = image.cols * image.channels();

	for (int i = 0; i < nl; i++) 
	{
		const uchar* imgDataIn = image.ptr<uchar>(i);
		uchar* imgDataOut = result.ptr<uchar>(i);
		for (int j = 0; j < nc; j++) 
		{
			imgDataOut[j] = (imgDataIn[j] / div) * div + div / 2; 
		}

	}
	cv::imshow("Image", result);
	cv::waitKey(0);

}

void colorReduceDereference(cv::Mat image, int div) 
{

}

void colorReduceModulo(cv::Mat image, int div) 
{

}

void colorReduceBinaryMask(cv::Mat image, int div) 
{

}

void colorReduceArtBinaryMask(cv::Mat image, int div) 
{

}

void colorReduce(cv::Mat& image, int div = 64) 
{
	int nl = image.rows;
	int nc = image.cols * image.channels();

	if (image.isContinuous()) 
	{
		// No padding !
		nc = nc * nl;
		nl = 1; // Dibuat jadi 1 d aja
	}
	
	for (int i = 0; i < nl; ++i) 
	{
		uchar* data = image.ptr<uchar>(i);
		for (int j = 0; j < nc; ++j) 
		{
			data[j] = (data[j] / div) * div + div / 2;
		}
	}

	cv::imshow("Image", image);
	cv::waitKey(0);
}


