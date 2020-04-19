#pragma once
#include<graphics.h>
#include"CPoint.h"
#include"CColor.h"
#include"CUi.h"

class CRect {
private:
	CPoint coord1, coord2;
	CColor BorderColor;
	CColor FillColor;
	bool isfilled;
public:
	CRect();
	CRect(int x1_, int y1_, int x2_, int y2_);

	COLORREF getBorderColor();
	COLORREF getFillColor();
	bool getIsFilled();

	void setBorderColor(int R, int G, int B);
	void setFillColor(int R, int G, int B);

	int Police(char strC[]);//检查用户输入的数据是否为空，空则返回1.否则返回0.

	void draw();
};