#pragma once
#include<graphics.h>
#include"CColor.h"

class CUi {
private:
	CColor BackgroundColor,WordColor;

public:
	CUi();
	CUi(int length,int width);

	static void Pre(void);//��̬��Ա���������������ֱ��ͨ�������÷���::�������ʸó�Ա������������Ҫ�����������ʡ�

	~CUi();
};