#pragma once
#include "Vehiculo.h"
class AutoDeportivo :public Vehiculo
{
private:
	string PaisOrigen;
public:
	AutoDeportivo(string patente, string marca, int modelo, int km, string PaisOrigen);
	~AutoDeportivo();
	string toJson();
};

