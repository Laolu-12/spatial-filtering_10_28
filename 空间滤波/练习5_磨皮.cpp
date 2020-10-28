#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{

	double i_minH = 0;
	double i_maxH = 20;

	double i_minS = 43;
	double i_maxS = 255;

	double i_minV = 55;
	double i_maxV = 255;

	cv::Size ksize;
	ksize.height = 5;
	ksize.width = 5;

	VideoCapture cap;
	cap.open(0);

	//磨皮思路：先转HSV格式后再二值化，对肤色进行提取，白色区域就可以当作掩膜；再对全图均值滤波，平滑处理后，利用掩膜截取肤色部分，实现“磨皮”效果
	
	while (1)
	{
		cv::Mat srcMat, hsvMat, binary, MeanMat,mask,dstMat;
		cap.read(srcMat);

		cvtColor(srcMat, hsvMat, COLOR_BGR2HSV); //RGB转HSV

		inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), binary); //二值化

		blur(srcMat, MeanMat, ksize); //均值滤波

		mask = binary;//掩膜

		MeanMat.copyTo(dstMat, mask);//仅保留掩膜区域

		imshow("原图", srcMat);
		imshow("二值化图像", binary);
		imshow("均值滤波后", MeanMat);
		imshow("靓仔出现！", dstMat);

		waitKey(30);

	}




	
}