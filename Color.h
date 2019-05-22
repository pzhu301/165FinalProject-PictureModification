#pragma once
/*
		Color
--------------------------
int blue
int green
int red
---------------------------
Color(int b)
corlor(int b,int g)
Color(int b,int g,int r)
setBlue(int b): void
setGreen(int g): void
setRed(int r): void
getBlue():int
getGreen():int
getRed():int
*/
class Color
{
private:
	int blue;
	int green;
	int red;

public:
	Color(int b)
	{
		blue = b;
	}
	Color(int b, int g)
	{
		blue = b;
		green = g;
	}
	Color(int b, int g, int r)
	{
		blue = b;
		green = g;
		red = r;
	}
	void setBlue(int b)
	{
		blue = b;
	}
	void setGreen(int g)
	{
		green = g;
	}
	void setRed(int r)
	{
		red = r;
	}
	int getBlue()
	{
		return blue;
	}
	int getGreen()
	{
		return green;
	}
	int getRed()
	{
		return red;
	}
};

