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
	    std::cout << "���ܴ���Ƶ" << std::endl;
		return -1;
	}
	cap.read(srcMat);

	medianBlur(srcMat, dstMat, 5); //��ֵ�˲�
	imshow("ԭͼ", srcMat);
	imshow("��ֵ�˲���", dstMat);


	waitKey(0);

}