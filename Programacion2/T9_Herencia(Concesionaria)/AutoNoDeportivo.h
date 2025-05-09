#pragma once
#include "Vehiculo.h"
class AutoNoDeportivo :public Vehiculo
{
private:
	string FechaImportacion;
public:
	AutoNoDeportivo(string patente, string marca, int modelo, int km, string FechaImportacion);
	~AutoNoDeportivo();
	string toJson();
};

