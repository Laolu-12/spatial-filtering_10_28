#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;

	cv::Size ksize;
	ksize.height = 5;
	ksize.width = 5;

	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频" << std::endl;
		return -1;
	}
	while (1)
	{
		cv::Mat srcMat, dstMat;
		cap.read(srcMat);

		blur(srcMat, dstMat, ksize); //均值滤波
		imshow("原图", srcMat);
		imshow("均值滤波后", dstMat);

		waitKey(30);
	}

}