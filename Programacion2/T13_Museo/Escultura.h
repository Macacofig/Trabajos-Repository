#pragma once
#include "Obra.h"
class Escultura :public Obra
{
private:
	int peso;
public:
	Escultura(string titulo, int precio, int peso);
	~Escultura();
	string toJson();
};

