#include"CPoly.h"  

CPoly::CPoly() :isfilled{ false } { //委托构造函数怎么实现呢？
	coord.resize(3);
	coord[0].setX(50); coord[0].setY(50); coord[1].setX(100); coord[1].setY(100); coord[2].setX(200); coord[2].setY(50);
	side = coord.size();
}

CPoly::CPoly(std::vector <CPoint> coord_) :isfilled{ false }
{

	for (int i = 0; i < coord_.size(); i++) {
		coord.resize(coord_.size());
		coord[i].setX(coord_[i].getX());
		coord[i].setY(coord_[i].getY());
	}
	side = coord_.size();
}

COLORREF CPoly::getBorderColor() { return (RGB(BorderColor.getColorR(), BorderColor.getColorG(), BorderColor.getColorB())); }
COLORREF CPoly::getFillColor() { return (RGB(FillColor.getColorR(), FillColor.getColorG(), FillColor.getColorB())); }
CPoint CPoly::getCoord(int i) { return coord[i]; }
bool CPoly::getIsFilled() { return isfilled; }

void CPoly::setBorderColor(int R, int G, int B) { BorderColor.setColor(R, G, B); }
void CPoly::setFillColor(int R, int G, int B) { FillColor.setColor(R, G, B); }

int CPoly::Police(char strC[]) {
	int a = 0, i = 0;
	for (; strC[i] != '\0'; i++)
	{
		if (strC[i] >= '0' && strC[i] <= '9' || strC[i] == ',') continue;
		else a = 1; break;
	}
	return a;
};//检查用户输入的数据是否为空，空则返回1.否则返回0.

void CPoly::draw() {
	
	char sides[100]{ '0' };//用于接收用户输入的边数
	char strC[100]{ '0' };//用于接收用户输入的各点坐标x1,y1,x2,y2...
	char strBorderColor[100]{ '0' };//用于接收用户输入的边线色
	char strFillColor[100]{ '0' };//用于接收用户输入的填充色
	int side_;//用于接收转换后的边数
	int Poly_Coord[100] = { 0 };//用于接收转换后的x1,y1,x2,y2...
	int CoordPoly[100]{ 0 };//作为数据从Poly_Coord[100]传到成员变量coord的中介
	int BorderColor_Coord[3] = { 0,0,0 };//用于接收转换后的边线色
	int FillColor_Coord[3] = { 0,0,0 };//用于接收转换后的填充色
	int i = 0, jay = 0;
	char fill;//用于接收用户是否填色的选择

	//输入顶点数
	do
	{
		i = 0, jay = 0;
		inputbox_getline("多边形顶点输入框", "请问您要画几边形？", sides, 100);
		side_ = atoi(sides);
		side = atoi(sides);
		if (Police(sides) == 0)//检测用户输入的数据是否合理
		{
			if (side_ < 3)
			{
				xyprintf(20, 170, "抱歉，多边形至少需要3个顶点。");
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

	//接下来输入坐标
	do
	{
		i = 0, jay = 0;
		inputbox_getline("画多边形窗口",
			"请按照（x1,y1,x2,y2,...,xn,yn）依次输入n边形的坐标，输入完毕请键入enter！",
			strC,
			sizeof(strC) / sizeof(*strC));

		if (Police(strC) == 0)
		{
			char* token = strtok(strC, ",");
			while (token != '\0')
			{
				Poly_Coord[i] = atoi(token);
				token = strtok('\0', ",");
				i++;
			}
			int k = 0;
			for (int i = 0; i < side_; i++) {
				coord.resize(side_);
				coord[i].setX(Poly_Coord[k]);
				coord[i].setY(Poly_Coord[k+1]);
				k+=2;
			}
			side = side_;
			

			if (i != (2 * side_))
			{
				xyprintf(20, 190, "您输入的坐标数目与顶点数目不匹配，请重新输入坐标。");
				delay_ms(2000);
				jay = 1;
				clearviewport();
			}
		}
		else
		{
			xyprintf(20, 190, "输入错误");
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
	setcolor(BorderColor.getColor());
	setfillcolor(FillColor.getColor());
	
	int k = 0;
	for (int j = 0; j < 2 * side; j += 2) {
		if (j > (2 * side - 2)) { break; }
		else {
			coord.resize(side);
			CoordPoly[j] = coord[k].getX();
			CoordPoly[j + 1] = coord[k].getY();
			k++;
		}
	}
	
	fillpoly(side, CoordPoly);

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