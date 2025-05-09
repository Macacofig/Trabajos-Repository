#include "ReservaSimple.h"

ReservaSimple::ReservaSimple(int idReserva, Cliente* c, Mascota* m, Atencion* a1)
	:Reserva(idReserva,c,m)
{
	this->a1 = a1;
}

ReservaSimple::~ReservaSimple()
{
}

string ReservaSimple::toJson()
{
	stringstream ss;
	ss << "{\"ReservaSimple\":{\"id\":" << idReserva
		<< ",\"cliente\":" << c->toJsonB()
		<< ",\"mascota\":"<<m->toJson()
		<<"},\"atencion\":"<<a1->toJson()<<"}";
	return ss.str();
}
