#pragma once
#include "EGBasico.h"
#include "Formato.h"

class Punto :public EGBasico
{
public:
	Punto(int id, int x, int y);
	~Punto();
	void setX(int x);
	void setY(int y);
	void dibujar() ;
	void borrar() ;
};

