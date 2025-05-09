#include "ReservaMultiple.h"

ReservaMultiple::ReservaMultiple(int idReserva, Cliente* c, Mascota* m, Atencion* a1, Atencion* a2)
	:Reserva(idReserva,c,m)
{
	this->a1 = a1;
	this->a2 = a2;
}

ReservaMultiple::~ReservaMultiple()
{
}

string ReservaMultiple::toJson()
{
	stringstream ss;
	ss << "{\"ReservaMultiple\":{\"id\":" << idReserva
		<< ",\"cliente\":" << c->toJsonB()
		<< ",\"mascota\":" << m->toJson()
		<< "},\"atencion1\":" << a1->toJson() << ",\"atencion2\":" << a2->toJson() << "}";
	return ss.str();
}
