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
		std::cout << "���ܴ���Ƶ" << std::endl;
		return -1;
	}
	cap.read(srcMat);

	blur(srcMat, dstMat, ksize); //��ֵ�˲�
	imshow("ԭͼ", srcMat);
	imshow("��ֵ�˲���", dstMat);


	waitKey(0);

}