#pragma once
#include "Exposicion.h"
#define ES 10
class ModExposiciones
{
private:
	int ind;
	Exposicion** exposiciones;
public:
	ModExposiciones();
	~ModExposiciones();
	Exposicion* buscar(int numero);
	void registrar(Exposicion* exposicion);
	string toJson();
};

