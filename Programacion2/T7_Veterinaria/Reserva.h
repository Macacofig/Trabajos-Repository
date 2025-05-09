#pragma once
#include "Mascota.h"
#include "Cliente.h"
#include "Atencion.h"
class Reserva
{
private:
	int id;
	Cliente* cliente;
	Mascota* mascota;
	Atencion* atencion;
public:
	Reserva(int id, Atencion* atencion, Cliente* cliente, Mascota* mascota);
	~Reserva();
	string toString();
};

