#include"CMenu.h"
CMenu::CMenu() {
	//initgraph(-1,-1);
	CUi::Pre(); //UI��������
	char choice;//�����û���ѡ��
	for (;;) 
	{
		CUi::Pre();
		xyprintf(0, 0, "��ӭ����Jay���壬����ݲ˵�ѡ������Ҫ���еĲ�����");
		xyprintf(10, 20, "1.��Բ");
		xyprintf(10, 40, "2.�������");
		xyprintf(10, 60, "3.������");
		xyprintf(10, 80, "4.�����Ļ");
		xyprintf(10, 100, "5.�˳�");
		xyprintf(0, 120, "����������ѡ��:");
		choice = getch();
		switch (choice) 
		{
		case '1': {CUi::Pre(); CCircle circle_{}; circle_.draw(); break; }//ÿ����һ���¶���ʱ����ʹ��newʵ�֣����º���delete���١�(���ʣ���ô���þ�̬��Ա�����������������أ�) e.g.CCircle* circle_ =new CCircle {};
		case '2': {CUi::Pre(); CPoly poly_{}; poly_.draw(); break; }
		case '3': {CUi::Pre(); CRect rect_{}; rect_.draw(); break; }
		case '4': {CUi::Pre(); CClearScreen clearscreen_{}; CUi::Pre(); break; }
		case '5': {CUi::Pre(); closegraph(); }
		default :  xyprintf(20, 170, "�������");
		}
		setviewport(0, 0, 2000, 150);
		clearviewport();
		setviewport(0, 0, 2000, 1000);//���³�ʼ������
	}
}
