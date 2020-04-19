#include"CPoly.h"  

CPoly::CPoly() :isfilled{ false } { //ί�й��캯����ôʵ���أ�
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
};//����û�����������Ƿ�Ϊ�գ����򷵻�1.���򷵻�0.

void CPoly::draw() {
	
	char sides[100]{ '0' };//���ڽ����û�����ı���
	char strC[100]{ '0' };//���ڽ����û�����ĸ�������x1,y1,x2,y2...
	char strBorderColor[100]{ '0' };//���ڽ����û�����ı���ɫ
	char strFillColor[100]{ '0' };//���ڽ����û���������ɫ
	int side_;//���ڽ���ת����ı���
	int Poly_Coord[100] = { 0 };//���ڽ���ת�����x1,y1,x2,y2...
	int CoordPoly[100]{ 0 };//��Ϊ���ݴ�Poly_Coord[100]������Ա����coord���н�
	int BorderColor_Coord[3] = { 0,0,0 };//���ڽ���ת����ı���ɫ
	int FillColor_Coord[3] = { 0,0,0 };//���ڽ���ת��������ɫ
	int i = 0, jay = 0;
	char fill;//���ڽ����û��Ƿ���ɫ��ѡ��

	//���붥����
	do
	{
		i = 0, jay = 0;
		inputbox_getline("����ζ��������", "������Ҫ�������Σ�", sides, 100);
		side_ = atoi(sides);
		side = atoi(sides);
		if (Police(sides) == 0)//����û�����������Ƿ����
		{
			if (side_ < 3)
			{
				xyprintf(20, 170, "��Ǹ�������������Ҫ3�����㡣");
				delay_ms(2000);
				jay = 1;
				clearviewport();
			}
		}
		else//�û���������ݲ���������
		{
			xyprintf(20, 170, "�������");
			jay = 1;
		}
	} while (jay == 1);

	//��������������
	do
	{
		i = 0, jay = 0;
		inputbox_getline("������δ���",
			"�밴�գ�x1,y1,x2,y2,...,xn,yn����������n���ε����꣬������������enter��",
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
				xyprintf(20, 190, "�������������Ŀ�붥����Ŀ��ƥ�䣬�������������ꡣ");
				delay_ms(2000);
				jay = 1;
				clearviewport();
			}
		}
		else
		{
			xyprintf(20, 190, "�������");
		}
	} while (jay == 1);

	//������ѡ�����ɫ�׶�
	CUi::Pre();
	xyprintf(20, 190, "ѡ�����ɫ�밴1�������밴0��(Ĭ��Ϊ��ɫ)");
	fill = getch();
	if (fill == '1')
	{
		do
		{
			i = 0, jay = 0;
			inputbox_getline("����ɫ����",
				"�������գ�R,G,B)����ʽ����RGB��ɫ�������밴enter����",
				strBorderColor,
				sizeof(strBorderColor) / sizeof(*strBorderColor));//�����û���������


			//�������û�����������Ƿ����
			if (Police(strBorderColor) == 0)
			{
				char* token = strtok(strBorderColor, ",");//����ĵ�һ���ַ���
				while (token != '\0')//���û����벻�ǿգ����ַ���ת������������������
				{
					BorderColor_Coord[i] = atoi(token);
					token = strtok('\0', ",");
					i++;
				}
				FillColor.setColor(BorderColor_Coord[0], BorderColor_Coord[1], BorderColor_Coord[2]);
				if (i != 3) {
					xyprintf(20, 170, "�������գ�R, G, B)����ʽ����RGB��ɫ������������");
					delay_ms(2000);
					jay = 1;
					clearviewport();
				}
			}
			else//�û���������ݲ���������
			{
				xyprintf(20, 170, "�������");
				jay = 1;
			}
		} while (jay == 1);

	}
	else if (fill == '0') { BorderColor.setColor(255, 255, 255); }
	else if (fill != '0')//�û���ѡ�������������
	{
		xyprintf(20, 210, "�������");
	}


	//������ѡ�����ɫ�׶�
	CUi::Pre();
	xyprintf(20, 190, "����밴1�������밴0��(Ĭ��Ϊ��ɫ)");
	fill = getch();
	if (fill == '1')
	{
		do
		{
			i = 0, jay = 0;
			inputbox_getline("���ɫ����",
				"�������գ�R,G,B)����ʽ����RGB��ɫ�������밴enter����",
				strFillColor,
				sizeof(strFillColor) / sizeof(*strFillColor));//�����û���������


			//�������û�����������Ƿ����
			if (Police(strFillColor) == 0)
			{
				char* token = strtok(strFillColor, ",");//����ĵ�һ���ַ���
				while (token != '\0')//���û����벻�ǿգ����ַ���ת������������������
				{
					FillColor_Coord[i] = atoi(token);
					token = strtok('\0', ",");
					i++;
				}
				FillColor.setColor(FillColor_Coord[0], FillColor_Coord[1], FillColor_Coord[2]);
				isfilled = true;
				if (i != 3) {
					xyprintf(20, 170, "�������գ�R, G, B)����ʽ����RGB��ɫ������������");
					delay_ms(2000);
					jay = 1;
					clearviewport();
				}
			}
			else//�û���������ݲ���������
			{
				xyprintf(20, 170, "�������");
				jay = 1;
			}
		} while (jay == 1);

	}
	else if (fill == '0') { FillColor.setColor(0, 0, 0); isfilled = false; }
	else if (fill != '0')//�û���ѡ�������������
	{
		xyprintf(20, 210, "�������");
	}

	//�����ǻ�ͼ�׶�
	setviewport(450, 150, 1700, 1000);//���û�ͼ����
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

	setviewport(20, 170, 450, 1000);//��ո�������
	setfillcolor(BLACK);
	clearviewport();
	setviewport(0, 0, 1700, 1000);
	
	
	//��������
	xyprintf(20, 210, "��������Ļ��ã�");
	setviewport(0, 0, 2000, 1000);
}
//draw()�����ڣ����뻹�е����⣬���統�û�ѡ���Ƿ����ñ���ɫ�����ɫʱ��������1��0������ַ�ʱ��δ����䱨����ơ�
//��������ɡ�