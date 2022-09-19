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
	std::cout << nc / 3 << std::endl;
	cv::imshow("Image", result);
	cv::waitKey(0);

}

void colorReduceDereference(cv::Mat image, int div) 
{
	int nl = image.rows;
	int nc = image.cols * image.channels();


	// x & 1 is equivalent to x % 2.
	// x >> 1 is equivalent to x / 2
	// x << 1 is equivalent to x * 2 
	// x << 2 is equivalent to x * 2 * 2 
	// x >> 2 is equivalent to x / 2 / 2
	// Mudah dan lebih cepat !
	// Bergantung kelipatan 
	uchar div2 = div >> 1; // div2 = div/2
	for (int i = 0; i < nl; i++) 
	{
		uchar* data = image.ptr<uchar>(i);
		for (int j = 0; j < nc; j++) 
		{
			*data++ = *data / div * div + div2;
		}
	}
	
	cv::imshow("image", image);
	cv::waitKey(0);

}

void colorReduceModulo(cv::Mat image, int div) 
{

	// Color Modulo
	int nl = image.rows;
	int nc = image.cols * image.channels();

	uchar div2 = div >> 1;

	for (int i = 0; i < nl; i++) 
	{

		uchar* data = image.ptr<uchar>(i);
		
		for (int j = 0; j < nc; j++) 
		{
			*data++ = *data - *data % div + div2;
		}
	
	}

	cv::imshow("image", image);
	cv::waitKey(0);

}

void colorReduceBinaryMask(cv::Mat image, int div) 
{
	int nl = image.rows;
	int nc = image.cols * image.channels();
	// Ini Cuman ngecilin nilai aja, Jadi Multipliernya ntar ga terlalu besar 
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);

	//Mask used to Round the pixel value
	// Basically ini Cuman ngekaliin si 0xFF by 2 * 2 * ... n
	// 255 * n * n * n 
	uchar mask = 0xFF << n;
	uchar div2 = 1 << (n - 1);

	for (int i = 0; i < nl; i++) 
	{
		uchar* data = image.ptr<uchar>(i);

		for (int j = 0; j < nc; j++) 
		{
			// Remmber ini , this is modulo
			*data &= mask; // mnasking The Data
			// Move the ptr, 
			*data++ |= div2;
		}
	}

	cv::imshow("image", image);
	cv::waitKey(0);

}

void colorReduceArtBinaryMask(cv::Mat image, int div) 
{

	int nl = image.rows;
	int nc = image.cols * image.channels();
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	int step = image.step; // Number of byters

	// Mask Used to round the pixel Value
	uchar mask = 0xff << n;
	uchar div2 = div >> 1;

	// Get The Pointer to the image buffer


	uchar* data = image.data;
	for (int i = 0; i < nl; i++) 
	{
		for (int j = 0; j < nc; j++) 
		{
			// Modulo with the mask value
			*(data + i) &= mask;
			*(data + i) += div2;
		}
		// Move to next line
		data += step;

	}

	cv::imshow("Image", image);
	cv::waitKey(0);




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


