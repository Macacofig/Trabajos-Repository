#pragma once
#include "Persona.h"
class Asiento
{
private:
	int fila;
	int columna;
	Persona* pasajero;
public:
	Asiento(int fila, int columna);
	~Asiento();
	int getFila();
	int getColumna();
	string toJson();

	Persona* getPasajero();
	void setPasajero(Persona* pasajero);
};

