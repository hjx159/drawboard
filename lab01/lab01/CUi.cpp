#include"CUi.h"

CUi::CUi():CUi(2000,1040) {}
CUi::CUi(int length, int width) {
	initgraph(length, width);
	Pre();
}

void CUi::Pre(void) {
	/*…Ë÷√ª≠∞ÂΩÁ√Ê*/

	int Coords[10] =
	{ 0, 150,
	450, 150,
	450, 1000,
	0, 1000,
	0, 150 };

	setfillcolor(BLACK);
	fillpoly(5, Coords);
	setcolor(LIGHTCYAN);
	line(0, 150, 1700, 150);
	line(450, 150, 450, 1500);
}

CUi::~CUi(){
	closegraph();
}
