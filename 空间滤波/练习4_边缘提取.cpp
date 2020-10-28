#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;
	cv::Mat srcMat, dstMatX,dstMatY;


	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频" << std::endl;
		return -1;
	}
	cap.read(srcMat);

	Sobel(srcMat, dstMatX,CV_16SC1,1,0,7); //x方向边缘提取
	Sobel(srcMat, dstMatY, CV_16SC1, 0, 1, 7);//Y方向边缘提取
	imshow("原图", srcMat);
	imshow("X方向边缘提取", dstMatX);
	imshow("Y方向边缘提取", dstMatY);


	waitKey(0);

}