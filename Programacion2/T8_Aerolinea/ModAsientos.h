#pragma once
#include "Asiento.h"
class ModAsientos
{
private:
	int ind;
	int tam;
	Asiento** asientos;
public:
	ModAsientos(int tam);
	~ModAsientos();
	void registarAsiento(Asiento* asiento);
	Asiento* buscar(int fila, int columna);
	string toJson();
};

