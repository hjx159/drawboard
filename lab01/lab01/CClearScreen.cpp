#include"CClearScreen.h"
CClearScreen::CClearScreen() {
	xyprintf(20, 270, "�����..."); delay_ms(1000);//����
	setfillcolor(BLACK);
	setviewport(450, 150, 2000, 1000);
	clearviewport();
	setviewport(0, 0, 2000, 1000);
}