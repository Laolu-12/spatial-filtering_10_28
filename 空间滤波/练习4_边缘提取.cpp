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
		std::cout << "���ܴ���Ƶ" << std::endl;
		return -1;
	}
	cap.read(srcMat);

	Sobel(srcMat, dstMatX,CV_16SC1,1,0,7); //x�����Ե��ȡ
	Sobel(srcMat, dstMatY, CV_16SC1, 0, 1, 7);//Y�����Ե��ȡ
	imshow("ԭͼ", srcMat);
	imshow("X�����Ե��ȡ", dstMatX);
	imshow("Y�����Ե��ȡ", dstMatY);


	waitKey(0);

}