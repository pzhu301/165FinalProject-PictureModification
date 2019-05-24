#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
/*
	Resize class
---------------------
-colPer:double
-rowPer:double
--------------------
+Resize()
+Resize(c:double,r:double)
+setColPer(c:double):void
+setRowPer(r:double):void
+getColPer():double
+getRowPer():double
+resizing(src:Mat):Mat
*/
class Resize
{
private:
	double colPer;
	double rowPer;
public:
	Resize()
	{
		colPer = 1;
		rowPer = 1;
	}
	Resize(double c, double r)
	{
		colPer = c;
		rowPer = r;
	}
	void setColPer(double c)
	{
		colPer = c;
	}
	void setRowPer(double r)
	{
		rowPer = r;
	}
	double getColPer()
	{
		return colPer;
	}
	double getRowPer()
	{
		return rowPer;
	}
	Mat resizing(Mat src)
	{
		Mat resImage;
		resize(src, resImage, Size(src.cols * colPer, src.rows * rowPer));
		return resImage;
	}
};

