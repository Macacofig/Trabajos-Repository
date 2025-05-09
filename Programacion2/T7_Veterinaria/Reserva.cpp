#include "Reserva.h"

Reserva::Reserva(int id, Atencion* atencion, Cliente* cliente, Mascota* mascota)
{
	this->id = id;
	this->atencion = atencion;
	this->cliente = cliente;
	this->mascota = mascota;
}

Reserva::~Reserva()
{
}

string Reserva::toString()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"cliente\":"<<cliente->toString_3()<<",\"mascota\":"<<mascota->toString()<<",\"atencion\":"<<atencion->toString()<<"}";
	return ss.str();
}
