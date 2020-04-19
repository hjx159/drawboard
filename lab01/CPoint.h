#pragma once
#include<string>
class CPoint {
private:
	int x;
	int y;
public:
	CPoint();
	CPoint(int x_, int y_) ;

	int getX() ;
	int getY() ;
	void setX(int x_) ;
	void setY(int y_) ;
};