#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main()
{
	VideoCapture cap;

	cap.open(0);
	if (!cap.isOpened())
	{
	    std::cout << "���ܴ���Ƶ" << std::endl;
		return -1;
	}

	while (1)
	{
		cv::Mat srcMat, dstMat;
		cap.read(srcMat);

		medianBlur(srcMat, dstMat, 7); //��ֵ�˲�
		imshow("ԭͼ", srcMat);
		imshow("��ֵ�˲���", dstMat);


		waitKey(30);
	}

}