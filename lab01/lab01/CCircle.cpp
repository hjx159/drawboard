#include"CCircle.h"

CCircle::CCircle() : CCircle(200, 200, 200){isfilled = false; }//委托构造函数能够减少代码量
CCircle::CCircle(int x_, int y_,  int radius_)
	:radius{ radius_ }, isfilled{ false }
{coord.setX(x_); coord.setY(y_); }


CPoint CCircle::getCoord() { return coord; };
int CCircle::getRadius() { return radius; }
COLORREF CCircle::getBorderColor() { return (RGB(BorderColor.getColorR(),BorderColor.getColorG(),BorderColor.getColorB())); }
COLORREF CCircle::getFillColor() { return (RGB(FillColor.getColorR(),FillColor.getColorG(),FillColor.getColorB())); }
bool CCircle::getIsFilled() { return isfilled; }


void CCircle::setRadius(int radius_) { radius = radius_; }
void CCircle::setCoord(int x_, int y_) { coord.setX(x_); coord.setY(y_); }
void CCircle::setBorderColor(int R,int G,int B) {
	BorderColor.setColor(R,G,B);
}
void CCircle::setFillColor(int R, int G, int B) {
	FillColor.setColor(R, G, B);
}

int CCircle::Police(char strC[]) {
	int a = 0, i = 0;
	for (; strC[i] != '\0'; i++)
	{
		if (strC[i] >= '0' && strC[i] <= '9' || strC[i] == ',') continue;
		else a = 1; break;
	}
	return a;
};//检查用户输入的数据是否为空，空则返回1.否则返回0.


void CCircle::draw() {
	
	char strC[100]{'0'};//用于接收用户输入的x,y,r
	char strBorderColor[100]{ '0' };//用于接收用户输入的边线色
	char strFillColor[100]{ '0' };//用于接收用户输入的填充色
	int Cir_Coord[3] = { 0,0,0 };//用于接收转换后的x,y.r
	int BorderColor_Coord[3] = { 0,0,0 };//用于接收转换后的边线色
	int FillColor_Coord[3] = { 0,0,0 };//用于接收转换后的填充色
	int i = 0, jay = 0;
	char fill;//用于接收用户是否填色的选择
	do
	{
		i = 0, jay = 0;
		//接收用户输入数据的窗口
		inputbox_getline("画圆窗口",
			"请您按照（x,y,r)的形式输入圆心坐标以及半径，结束请按enter键。",
			strC,
			sizeof(strC) / sizeof(*strC));
		


		//下面检测用户输入的数据是否合理
		if (Police(strC) == 0)
		{
			char* token = strtok(strC, ",");//输入的第一个字符串
			while (token != '\0')//若用户输入不是空，则将字符串转换并存入整型数组中
			{
				Cir_Coord[i]= atoi(token);
				token = strtok('\0', ",");
				i++;
			}
			
			coord.setX(Cir_Coord[0]);
			coord.setY(Cir_Coord[1]);
			radius = Cir_Coord[2];
			if (i != 3) {
				xyprintf(20, 170, "请您按照（x, y, r)的形式输入圆心坐标以及半径共三个参数！");
				delay_ms(2000);
				jay = 1;
				clearviewport();
			}
		}
		else//用户输入的数据不合理，报错！
		{
			xyprintf(20, 170, "输入错误");
			jay = 1;
		}
	} while (jay == 1);
	
	//下面是选择边线色阶段
	CUi::Pre();
	xyprintf(20, 190, "选择边线色请按1，否则请按0。(默认为白色)");
	fill = getch();
	if (fill == '1')
	{
		do
		{
			i = 0, jay = 0;
			inputbox_getline("边线色窗口",
				"请您按照（R,G,B)的形式输入RGB颜色，结束请按enter键。",
				strBorderColor,
				sizeof(strBorderColor) / sizeof(*strBorderColor));//接收用户输入数据


			//下面检测用户输入的数据是否合理
			if (Police(strBorderColor) == 0)
			{
				char* token = strtok(strBorderColor, ",");//输入的第一个字符串
				while (token != '\0')//若用户输入不是空，则将字符串转换并存入整型数组中
				{
					BorderColor_Coord[i] = atoi(token);
					token = strtok('\0', ",");
					i++;
				}
				FillColor.setColor(BorderColor_Coord[0], BorderColor_Coord[1], BorderColor_Coord[2]);
				if (i != 3) {
					xyprintf(20, 170, "请您按照（R, G, B)的形式输入RGB颜色的三个参数！");
					delay_ms(2000);
					jay = 1;
					clearviewport();
				}
			}
			else//用户输入的数据不合理，报错！
			{
				xyprintf(20, 170, "输入错误");
				jay = 1;
			}
		} while (jay == 1);

	}
	else if (fill == '0') { BorderColor.setColor(255, 255, 255); }
	else if (fill != '0')//用户的选择很暧昧，报错！
	{
		xyprintf(20, 210, "输入错误");
	}


	//下面是选择填充色阶段
	CUi::Pre();
	xyprintf(20, 190, "填充请按1，否则请按0。(默认为黑色)");
	fill = getch();
	if (fill == '1')
	{	
		do
		{
			i = 0, jay = 0;
			inputbox_getline("填充色窗口",
				"请您按照（R,G,B)的形式输入RGB颜色，结束请按enter键。",
				strFillColor,
				sizeof(strFillColor) / sizeof(*strFillColor));//接收用户输入数据


			//下面检测用户输入的数据是否合理
			if (Police(strFillColor) == 0)
			{
				char* token = strtok(strFillColor, ",");//输入的第一个字符串
				while (token != '\0')//若用户输入不是空，则将字符串转换并存入整型数组中
				{
					FillColor_Coord[i] = atoi(token);
					token = strtok('\0', ",");
					i++;
				}
				FillColor.setColor(FillColor_Coord[0], FillColor_Coord[1], FillColor_Coord[2]);
				isfilled = true;
				if (i != 3) {
					xyprintf(20, 170, "请您按照（R, G, B)的形式输入RGB颜色的三个参数！");
					delay_ms(2000);
					jay = 1;
					clearviewport();
				}
			}
			else//用户输入的数据不合理，报错！
			{
				xyprintf(20, 170, "输入错误");
				jay = 1;
			}
		} while (jay == 1);
		
	}
	else if (fill == '0') { FillColor.setColor(0, 0, 0); isfilled = false; }
	else if (fill != '0')//用户的选择很暧昧，报错！
	{
		xyprintf(20, 210, "输入错误");
	}

	//下面是绘图阶段
	setviewport(450, 150, 1700, 1000);//设置绘图视区
	setcolor(getBorderColor());
	setfillcolor(getFillColor());
	fillellipse(coord.getX(),coord.getY(),radius,radius);
	setviewport(20, 170, 450, 1000);//清空副操作栏
	setfillcolor(BLACK);
	clearviewport();
	setviewport(0, 0, 1700, 1000);
	//继续画旅
	xyprintf(20, 210, "请继续您的画旅！");
	setviewport(0, 0, 2000, 1000);
}  

//draw()函数内，代码还有点问题，比如当用户选择是否设置边线色和填充色时，若输入1或0以外的字符时，未完成其报错机制。
//待后续完成。
