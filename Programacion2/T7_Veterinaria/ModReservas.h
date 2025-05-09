#pragma once
#include "Reserva.h"
class ModReservas
{
private:
	int ind;
	int tam;
	Reserva** reservas;
public:
	ModReservas(int tam);
	~ModReservas();
	void registar(Reserva* reserva);
	string toString();
};

