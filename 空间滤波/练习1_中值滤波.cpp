#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;
	cv::Mat srcMat,dstMat;

	cap.open(0);
	if (!cap.isOpened())
	{
	    std::cout << "不能打开视频" << std::endl;
		return -1;
	}
	cap.read(srcMat);

	medianBlur(srcMat, dstMat, 5); //中值滤波
	imshow("原图", srcMat);
	imshow("中值滤波后", dstMat);


	waitKey(0);

}