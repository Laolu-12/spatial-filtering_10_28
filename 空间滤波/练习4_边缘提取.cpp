#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;
	int ksize=7;

	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频" << std::endl;
		return -1;
	}
	while (1)
	{
		cv::Mat srcMat, dstMatX, dstMatY;
		cap.read(srcMat);

		Sobel(srcMat, dstMatX, CV_16SC1, 1, 0, ksize); //x方向边缘提取
		Sobel(srcMat, dstMatY, CV_16SC1, 0, 1, ksize);//Y方向边缘提取
		imshow("原图", srcMat);
		imshow("X方向边缘提取", dstMatX);
		imshow("Y方向边缘提取", dstMatY);


		waitKey(30);
	}

}