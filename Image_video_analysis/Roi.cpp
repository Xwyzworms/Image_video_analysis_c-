#include "Roi.h"


cv::Mat drawROIFromImage(std::string pathImage, std::string pathLogo) 
{
	cv::Mat image = cv::imread(pathImage);
	cv::Mat logo = cv::imread(pathLogo);

	cv::Rect mRoi =  
		cv::Rect(image.cols - logo.cols,
		image.rows - logo.rows,
		logo.cols, logo.rows // roi size
	);

	cv::Mat imageRoi(image, mRoi);
	logo.copyTo(imageRoi);

	cv::imshow("Image", image);
	cv::waitKey(0);
	
	return imageRoi;
}

void maskImage(std::string imagePath, std::string logoPath)
{
	cv::Mat image = cv::imread(imagePath);
	cv::Mat logo = cv::imread(logoPath);

	// ImageRoi point to image
	cv::Mat imageRoi = image(cv::Rect(image.cols - logo.cols,
		image.rows - logo.rows,
		logo.cols, logo.rows));

	// Mask the logo ( logo need to be gray scale)
	cv::Mat mask(logo);

	logo.copyTo(imageRoi, mask);
	cv::imshow("image", image);
    cv::waitKey(0);
}
