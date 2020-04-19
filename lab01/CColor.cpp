#include"CColor.h"
CColor::CColor() :CColor(255,0,0) {}
CColor::CColor(int R_, int G_, int B_) : R{ R_ }, G{ G_ }, B{ B_ } {}

void CColor::setColor(int R_, int G_, int B_) { R = R_; G = G_; B = B_; }

int CColor::getColorR() { return R; };
int CColor::getColorG() { return G; };
int CColor::getColorB() { return B; };
int CColor::getColor() { return RGB(R, G, B); }

