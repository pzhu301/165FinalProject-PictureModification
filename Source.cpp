#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Brightness.h"
#include "Rotation.h"
#include "Resize.h"

using namespace cv;
using namespace std;



int main(int argc, char** argv)
{
	Mat src, dst;
	string input = "", check1 = "", thro, again;
	char againChar;
	Brightness b;
	Rotation r;
	Resize re;
	double a, angle, row, col;
	int be, choice;
	bool check = false;

	do {
		//get the image file
		cout << "Please enter the name of file (include file extension):";
		cin >> input;
		//input validation
		try
		{
			int len = input.length();
			for (int i = 4; i > 0; i--)
			{
				check1 += input[len - i];
			}
			if (check1.compare(".jpg"))
			{
				thro = check1;
				throw thro;
			}
		}
		catch (string thro)
		{

			cout << "Error! Invalid input. Program Ending" << thro << endl;
			return -1;
		}
		//file exception
		try
		{
			input = "D:\\openCV\\opencv\\sources\\samples\\data\\" + input;
			src = imread(input);
			if (src.empty())
			{
				cout << "Can't find the file. Program ending." << endl;
				return 1;
			}
			namedWindow("k");
			imshow("k", src);
			waitKey(0);
		}
		catch (Exception& e)
		{
			cout << "Invalid input for file name." << e.what() << endl;
			return 1;
		}

		cout << "Please choose one modification:\n 1.brightness\n 2.rotation\n 3.resize\n ";
		cin >> choice;
		Mat rot = r.rotate(src);
		Mat resize = re.resizing(src);
		switch (choice)
		{
		case 1:
			//brightness
			cout << "Please enter the alpha for brightness[1.0-3.0]:";
			cin >> a;
			//input exception
			try
			{
				if (a < 1 or a>3.0)
					throw a;
			}
			catch (double a)
			{
				cout << "Error. Only enter [1.0-3.0]. Program Ending." << endl;
				return 1;
			}

			b.setAlpha(a);

			cout << "Please enter the beta for brightness[0-100]:";
			cin >> be;
			//input exception
			try
			{
				if (be < 0 or be>100)
					throw be;
			}
			catch (int be)
			{
				cout << "Error. Only enter [0-100]. Program Ending." << endl;
				return 1;
			}
			b.setBeta(be);

			b.changeBrightness(src);
			break;
		case 2:
			//rotation
			cout << "Please enter the angle for rotation:";
			cin >> angle;
			r.setAngle(angle);

			imshow("Rotation", rot);
			waitKey();
			break;
		case 3:
			//resize image
		//resize the row
			cout << "Please enter how many percentage of width you want to resize:";
			cin >> row;
			//input exception
			try
			{
				if (row < 0 or row>1)
					throw row;
			}
			catch (double row)
			{
				cout << "Error. Only enter [0.0-1.0]. Program Ending." << endl;
				return 1;
			}
			re.setRowPer(row);
			//resize the colum
			cout << "Please enter how many percentage of height you want to resize:";
			cin >> col;
			//input exception
			try
			{
				if (col < 0 or col>1)
					throw col;
			}
			catch (double col)
			{
				cout << "Error. Only enter [0.0-1.0]. Program Ending." << endl;
				return 1;
			}
			re.setColPer(col);
			imshow("Resizing", resize);
			waitKey(0);
			break;

		default:
			cout << "Invalid input.\n";
			break;
		}
		cout << "Do you want to do it again? Y/N:";
		cin.ignore();
		getline(cin, again);
		againChar = again[0];
		againChar = toupper(againChar);
		if (againChar == 'Y')
			check = false;
		else if (againChar == 'N')
			check = true;
		else
			cout << "Invalid input.";

	} while (check == false);
	cout << "Prgram ending. Have a good day.";


	return 0;
}
