#pragma once
#include<graphics.h>
#include"CColor.h"

class CUi {
private:
	CColor BackgroundColor,WordColor;

public:
	CUi();
	CUi(int length,int width);

	static void Pre(void);//静态成员函数，在类外可以直接通过域作用符‘::’来访问该成员函数，而不需要创建对象后访问。

	~CUi();
};