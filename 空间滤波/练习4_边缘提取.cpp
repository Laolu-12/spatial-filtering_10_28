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
		std::cout << "���ܴ���Ƶ" << std::endl;
		return -1;
	}
	while (1)
	{
		cv::Mat srcMat, dstMatX, dstMatY;
		cap.read(srcMat);

		Sobel(srcMat, dstMatX, CV_16SC1, 1, 0, ksize); //x�����Ե��ȡ
		Sobel(srcMat, dstMatY, CV_16SC1, 0, 1, ksize);//Y�����Ե��ȡ
		imshow("ԭͼ", srcMat);
		imshow("X�����Ե��ȡ", dstMatX);
		imshow("Y�����Ե��ȡ", dstMatY);


		waitKey(30);
	}

}