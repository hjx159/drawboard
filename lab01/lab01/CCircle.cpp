#include"CCircle.h"

CCircle::CCircle() : CCircle(200, 200, 200){isfilled = false; }//ί�й��캯���ܹ����ٴ�����
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
};//����û�����������Ƿ�Ϊ�գ����򷵻�1.���򷵻�0.


void CCircle::draw() {
	
	char strC[100]{'0'};//���ڽ����û������x,y,r
	char strBorderColor[100]{ '0' };//���ڽ����û�����ı���ɫ
	char strFillColor[100]{ '0' };//���ڽ����û���������ɫ
	int Cir_Coord[3] = { 0,0,0 };//���ڽ���ת�����x,y.r
	int BorderColor_Coord[3] = { 0,0,0 };//���ڽ���ת����ı���ɫ
	int FillColor_Coord[3] = { 0,0,0 };//���ڽ���ת��������ɫ
	int i = 0, jay = 0;
	char fill;//���ڽ����û��Ƿ���ɫ��ѡ��
	do
	{
		i = 0, jay = 0;
		//�����û��������ݵĴ���
		inputbox_getline("��Բ����",
			"�������գ�x,y,r)����ʽ����Բ�������Լ��뾶�������밴enter����",
			strC,
			sizeof(strC) / sizeof(*strC));
		


		//�������û�����������Ƿ����
		if (Police(strC) == 0)
		{
			char* token = strtok(strC, ",");//����ĵ�һ���ַ���
			while (token != '\0')//���û����벻�ǿգ����ַ���ת������������������
			{
				Cir_Coord[i]= atoi(token);
				token = strtok('\0', ",");
				i++;
			}
			
			coord.setX(Cir_Coord[0]);
			coord.setY(Cir_Coord[1]);
			radius = Cir_Coord[2];
			if (i != 3) {
				xyprintf(20, 170, "�������գ�x, y, r)����ʽ����Բ�������Լ��뾶������������");
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
	setcolor(getBorderColor());
	setfillcolor(getFillColor());
	fillellipse(coord.getX(),coord.getY(),radius,radius);
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
