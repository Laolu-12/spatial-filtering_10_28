#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;
	cv::Mat srcMat, dstMat;
	cv::Size ksize;
	ksize.height = 5;
	ksize.width = 5;

	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频" << std::endl;
		return -1;
	}
	cap.read(srcMat);

	GaussianBlur(srcMat, dstMat, ksize,1,1); //高斯滤波
	imshow("原图", srcMat);
	imshow("高斯滤波后", dstMat);


	waitKey(0);

}