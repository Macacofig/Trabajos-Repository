#pragma once
#include "Reserva.h"
class ReservaSimple :public Reserva
{
private:
	Atencion* a1;
public:
	ReservaSimple(int idReserva, Cliente* c, Mascota* m, Atencion* a1);
	~ReservaSimple();
	string toJson();
};

