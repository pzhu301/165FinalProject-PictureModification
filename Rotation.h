#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
/*
	Rotation class
---------------------
-angle : double
---------------------
+Rotation(a: double)
+setAngle(a: double):void
+getAngle(): double
+rotate(scr: Mat):Mat
*/
class Rotation
{
private:
	double angle;

public:
	Rotation()
	{
		angle = 0;
	}
	Rotation(double a)
	{
		angle = a;
	}
	void setAngle(double a)
	{
		angle = a;
	}
	double getAngle()
	{
		return angle;
	}
	Mat rotate(Mat src)
	{
		if (src.empty())
		{
			cout << "Cant't find the file";
			exit(0);
		}
		cout << angle;
		Mat dst;
		Point2f pt(src.cols / 2.0, src.rows / 2.0); // rotation center
		Mat r = getRotationMatrix2D(pt, angle, 1.0);
		warpAffine(src, dst, r, Size(src.cols, src.rows));
		return dst;
	}
};

