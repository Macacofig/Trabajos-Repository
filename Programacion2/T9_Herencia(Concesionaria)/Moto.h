#pragma once
#include "Vehiculo.h"
class Moto :public Vehiculo
{
private:
	string tipo;
public:
	Moto(string patente, string marca, int modelo, int km,string tipo);
	~Moto();
	string toJson();
};

