#pragma once
#include<graphics.h>
#include"CColor.h"
#include"CPoint.h"
#include<vector>
#include"CUi.h"
class CPoly {
private:
	int side;
	std::vector <CPoint> coord;
	CColor BorderColor;
	CColor FillColor;
	bool isfilled;

public:
	CPoly();
	
	CPoly(std::vector <CPoint> coord_);
	
	COLORREF getBorderColor();
	COLORREF getFillColor();
	CPoint getCoord(int i);
	bool getIsFilled();

	void setBorderColor(int R, int G, int B);
	void setFillColor(int R, int G, int B);

	int Police(char strC[]);//检查用户输入的数据是否为空，空则返回1.否则返回0.

	void draw();
};