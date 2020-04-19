#include"CPoint.h"
CPoint::CPoint() :CPoint (0,0){}
CPoint::CPoint(int x_, int y_) : x{ x_ }, y{y_} {}

int CPoint::getX() { return x; };
int CPoint::getY() { return y; };
void CPoint::setX(int x_) { x = x_; };
void CPoint::setY(int y_) { y = y_; };
