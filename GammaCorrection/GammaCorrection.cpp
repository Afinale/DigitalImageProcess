#include <opencv2\opencv.hpp>
#include<cmath>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("Img_GammaCorrection.bmp", 0); 
	imshow("Src", img);
	int row = img.rows;
	int col = img.cols;
	Mat Dst(row, col, CV_8UC1);


	//��������ͼ��ͳ�Ƹ���
	for (int i = 0; i < row; i++)
	{
		uchar* p = img.ptr<uchar>(i);
		uchar* q = Dst.ptr<uchar>(i);
		for (int j = 0; j < col; j++)
		{
			q[j] = pow(p[j]/255.0,1/2.4)*255.0;
		}
	}
	imshow("Dst", Dst);
	
	imwrite("GammaCorrection.bmp", Dst);
	
	
	//ֱ��ͼ����
	//	int grayNum[256] = { 0 }; // �����±�ֵ���ڻҶ�ֵ
	////��������ͼ��ͳ�Ƹ���
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		grayNum[Dst.at<uchar>(i, j)] = grayNum[Dst.at<uchar>(i, j)] + 1;
	//	}
	//}



	//// ��ֱ��ͼ
	//double maxVal = 0;
	//int i = 0;
	//while (1)
	//{
	//	if (i > 255)
	//		break;
	//	if (grayNum[i] > maxVal)
	//		maxVal = grayNum[i];
	//	i++;
	//}

	//int bin_num = 256; // [0,255]��256��bin
	//Mat histImg(bin_num, bin_num, CV_8U, Scalar(255)); //���ɰ�ɫ����(255)
	//int hpt = static_cast<int>(0.9 * bin_num);
	////ÿ��bin����һ����ֱ��
	//for (int i = 0; i < bin_num; i++) {
	//	printf("%d ", i);
	//	int binVal = grayNum[i];
	//	int intensity = static_cast<int>(binVal * hpt / maxVal);  // ����ת��Ϊ���ȣ�ͬ������ĻҶ�ֵҲ����ת��Ϊ����
	//	//����֮�����һ����
	//	line(histImg, Point(i, bin_num),       //ֱ��ͼ����ĵ�
	//		Point(i, bin_num - intensity),     //ֱ��ͼ����ĵ�
	//		Scalar::all(0));
	//}
	//imshow("histImg", histImg);
	//imwrite("DsthistImg.bmp", histImg);

	waitKey(0);
	return 0;
}