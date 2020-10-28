#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;

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

		medianBlur(srcMat, dstMat, 7); //中值滤波
		imshow("原图", srcMat);
		imshow("中值滤波后", dstMat);


		waitKey(30);
	}

}