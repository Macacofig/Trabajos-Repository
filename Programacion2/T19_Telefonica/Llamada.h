#pragma once
#include "Accion.h"
class Llamada :public Accion
{
private:
	int durmin;
public:
	Llamada(int id, int fecha, int durmin);
	~Llamada();
	int getDurmin();
	string toJson();
};
