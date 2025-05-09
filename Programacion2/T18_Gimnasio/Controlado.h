#pragma once
#include "Grupo.h"
#include "ListaGen.h"
#include "Socio.h"
class Controlado :public Grupo
{
private:
public:
	Controlado(string id);
	~Controlado();
	string toJson();
};

