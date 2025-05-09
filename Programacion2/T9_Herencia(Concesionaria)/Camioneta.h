#pragma once
#include "Vehiculo.h"
class Camioneta : public Vehiculo
{
private:
	int CapCarga;
public:
	Camioneta(string patente, string marca, int modelo, int km, int CapCarga);
	~Camioneta();
	string toJson();
};

