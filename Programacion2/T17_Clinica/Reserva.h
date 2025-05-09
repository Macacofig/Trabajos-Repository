#pragma once
#include "Atencion.h"
#include "Cliente.h"
#include "Mascota.h"
class Reserva
{
protected:
	int idReserva;
	Cliente* c;
	Mascota* m;
public:
	Reserva(int idReserva,Cliente* c,Mascota* m);
	~Reserva();
	int getIdRes();
	virtual string toJson()=0;
	static string toStatic(Reserva* reserva);
};

