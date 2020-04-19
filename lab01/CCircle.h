#pragma once
#include<graphics.h>
#include"CPoint.h"
#include"CColor.h"
#include"CUi.h"

class CCircle {
private:
	CPoint coord;
	int radius;
	CColor BorderColor;
	CColor FillColor;
	bool isfilled;

public:
	CCircle();
	CCircle(int x_, int y_, int radius_);
	
	int getRadius();
	CPoint getCoord();
	COLORREF getBorderColor();
	COLORREF getFillColor();
	bool getIsFilled();
	
	
	void setRadius(int radius_);
	void setCoord(int x_, int y_);
	void setBorderColor(int R, int G, int B);
	void setFillColor(int R, int G, int B);
	
	int Police(char strC[]);//检查用户输入的数据是否为空，空则返回1.否则返回0.

	void draw();


};