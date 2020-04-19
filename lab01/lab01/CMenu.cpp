#include"CMenu.h"
CMenu::CMenu() {
	//initgraph(-1,-1);
	CUi::Pre(); //UI界面设置
	char choice;//接收用户的选择
	for (;;) 
	{
		CUi::Pre();
		xyprintf(0, 0, "欢迎进入Jay画板，请根据菜单选择您想要进行的操作：");
		xyprintf(10, 20, "1.画圆");
		xyprintf(10, 40, "2.画多边形");
		xyprintf(10, 60, "3.画矩形");
		xyprintf(10, 80, "4.清除屏幕");
		xyprintf(10, 100, "5.退出");
		xyprintf(0, 120, "请输入您的选择:");
		choice = getch();
		switch (choice) 
		{
		case '1': {CUi::Pre(); CCircle circle_{}; circle_.draw(); break; }//每声明一个新对象时必须使用new实现，完事后用delete销毁。(疑问：那么利用静态成员来计数的意义在哪呢？) e.g.CCircle* circle_ =new CCircle {};
		case '2': {CUi::Pre(); CPoly poly_{}; poly_.draw(); break; }
		case '3': {CUi::Pre(); CRect rect_{}; rect_.draw(); break; }
		case '4': {CUi::Pre(); CClearScreen clearscreen_{}; CUi::Pre(); break; }
		case '5': {CUi::Pre(); closegraph(); }
		default :  xyprintf(20, 170, "输入错误");
		}
		setviewport(0, 0, 2000, 150);
		clearviewport();
		setviewport(0, 0, 2000, 1000);//重新初始化视区
	}
}
