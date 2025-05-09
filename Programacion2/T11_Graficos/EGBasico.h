#pragma once
#include "ElementoGrafico.h"
class EGBasico :public ElementoGrafico
{
protected:
	int x;
	int y;
public:
	EGBasico(int id, string tipo,int x,int y);
	~EGBasico();
	int getX();
	int getY();
};

