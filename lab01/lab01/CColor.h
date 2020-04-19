#pragma once
#include<graphics.h>
class CColor {
private:
	int R, G, B;
public:
	CColor();
	CColor(int R_, int G_, int B_);
	
	void setColor(int R_, int G_, int B_);
	
	int getColorR();
	int getColorG();
	int getColorB();
	int getColor();

		
};