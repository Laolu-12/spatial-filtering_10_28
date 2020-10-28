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

	//ĥƤ˼·����תHSV��ʽ���ٶ�ֵ�����Է�ɫ������ȡ����ɫ����Ϳ��Ե�����Ĥ���ٶ�ȫͼ��ֵ�˲���ƽ�������������Ĥ��ȡ��ɫ���֣�ʵ�֡�ĥƤ��Ч��
	
	while (1)
	{
		cv::Mat srcMat, hsvMat, binary, MeanMat,mask,dstMat;
		cap.read(srcMat);

		cvtColor(srcMat, hsvMat, COLOR_BGR2HSV); //RGBתHSV

		inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), binary); //��ֵ��

		blur(srcMat, MeanMat, ksize); //��ֵ�˲�

		mask = binary;//��Ĥ

		MeanMat.copyTo(dstMat, mask);//��������Ĥ����

		imshow("ԭͼ", srcMat);
		imshow("��ֵ��ͼ��", binary);
		imshow("��ֵ�˲���", MeanMat);
		imshow("���г��֣�", dstMat);

		waitKey(30);

	}




	
}