#pragma once
#include "Accion.h"
class Descarga :public Accion
{
private:
	int megas;
public:
	Descarga(int id, int megas, int fecha);
	~Descarga();
	int getMegas();
	string toJson();
};

