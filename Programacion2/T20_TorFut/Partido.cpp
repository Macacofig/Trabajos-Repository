#include "Partido.h"

Partido::Partido(int id, Equipo* local, Equipo* visitante)
{
	this->id = id;
	this->local = local;
	this->visitante = visitante;
}

Partido::~Partido()
{
}

string Partido::toString()
{
	return string();
}

string Partido::toStatic()
{
	return string();
}
