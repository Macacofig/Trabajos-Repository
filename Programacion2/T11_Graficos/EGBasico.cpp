#include "EGBasico.h"

EGBasico::EGBasico(int id, string tipo, int x, int y)
	:ElementoGrafico(id,tipo)
{
	this->x = x;
	this->y = y;
}

EGBasico::~EGBasico()
{
}

int EGBasico::getX()
{
	return x;
}

int EGBasico::getY()
{
	return y;
}
