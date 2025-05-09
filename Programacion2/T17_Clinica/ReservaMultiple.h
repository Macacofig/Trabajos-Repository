#pragma once
#include "Reserva.h"
class ReservaMultiple :public Reserva
{
private:
	Atencion* a1;
	Atencion* a2;
public:
	ReservaMultiple(int idReserva, Cliente* c, Mascota* m, Atencion* a1, Atencion* a2);
	~ReservaMultiple();
	string toJson();
};

