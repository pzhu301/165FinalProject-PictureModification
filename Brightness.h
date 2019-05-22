#pragma once
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

/*
	class Brightness
-------------------------
alpha:double[1.0-3.0]
beta:int[0-100]
-------------------------
Brigthness(double a, int b)
setAlpha():void
setBeta():void
getAlpha():double
getBeta():int
changeBrightness(Mat image):void
*/

class Brightness
{

private:

double alpha;
int beta;
public:
	Brightness()
	{
		alpha = 0;
		beta = 0;
	}
	Brightness(double a, int b)
	{
		alpha = a;
		beta = b;
	}

void setAlpha(double a)
{
	try
	{
		if (a < 1 or a>3)
			throw a;
		else
			alpha = a;
	}
		catch (double a)
		{
			cout << "Invalid input(Input should be [1.0-3.0])" << a << endl;
		}
	}
	void setBeta(int b)
	{
		try
		{
			if (b < 0 or b>100)
				throw b;
			else
				beta = b;
		}
		catch (double b)
		{
			cout << "Invalid input(Input should be [0-100])" << b << endl;
		}
	}
	double getAlpha()
	{
		return alpha;
	}
	int getBeta()
	{
		return beta;
	}
	void changeBrightness(Mat image)
	{
		Mat new_image = Mat::zeros(image.size(), image.type());
		for (int y = 0; y < image.rows; y++)
		{
			for (int x = 0; x < image.cols; x++)
			{
				for (int c = 0; c < image.channels(); c++)
				{
					new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
				}
			}
		}
		imshow("New Image", new_image);
		waitKey();
	}
};

