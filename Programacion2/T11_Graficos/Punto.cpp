#include "Punto.h"

Punto::Punto(int id, int x, int y)
	:EGBasico(id,"Punto",  x, y)
{
}

Punto::~Punto()
{
}

void Punto::setX(int x)
{
	this->x = x;
}

void Punto::setY(int y)
{
	this->y = y;
}

void Punto::dibujar()
{
	gotoxy(x, y);
	cout << "*";
}

void Punto::borrar()
{
	gotoxy(x, y);
	cout << " ";
}
