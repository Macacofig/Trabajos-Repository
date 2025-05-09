#include "Reserva.h"

Reserva::Reserva(int idReserva, Cliente* c, Mascota* m)
{
	this->idReserva = idReserva;
	this->c = c;
	this->m = m;
}

Reserva::~Reserva()
{
}

int Reserva::getIdRes()
{
	return idReserva;
}

string Reserva::toStatic(Reserva* reserva)
{
	return reserva->toJson();
}
