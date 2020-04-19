#pragma once
#include"CColor.h"
class CShape {
private:
	CColor BorderColor;
	CColor FillColor;
	bool isfilled;
public:
	COLORREF getBorderColor() { return (RGB(BorderColor.getColorR(), BorderColor.getColorG(), BorderColor.getColorB())); }
	COLORREF getFillColor() { return (RGB(FillColor.getColorR(), FillColor.getColorG(), FillColor.getColorB())); }
	bool getIsFilled() { return isfilled; };

	void setBorderColor(int R, int G, int B) { BorderColor.setColor(R, G, B); }
	void setFillColor(int R, int G, int B) { FillColor.setColor(R, G, B); }
	void setIsFilled(bool isfilled_) { isfilled = isfilled_; }

	int Police(char strC[]) {
		int a = 0, i = 0;
		for (; strC[i] != '\0'; i++)
		{
			if (strC[i] >= '0' && strC[i] <= '9' || strC[i] == ',') continue;
			else a = 1; break;
		}
		return a;
	};//����û�����������Ƿ�Ϊ�գ����򷵻�1.���򷵻�0.


};