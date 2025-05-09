#pragma once
#include "Accion.h"
class Llamada :public Accion
{
private:
	int durmin;
public:
	Llamada(int id, long fecha,int durmin);
	~Llamada();
	int getDurmin();
	string toJson();
};

