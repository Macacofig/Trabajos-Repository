#include "Sesion.h"

Sesion::Sesion(int fecha)
{
	this->fecha = fecha;
}

Sesion::~Sesion()
{
}

int Sesion::getFecha()
{
	return fecha;
}

ListaGen<Socio>& Sesion::getSocios()
{
	return socios;
}

bool Sesion::operator==(Sesion* s)
{
	return fecha=s->getFecha();
}

string Sesion::toString()
{
	stringstream ss;
	ss << "{\"fecha\":" << fecha << ",\"asistentes\":" << socios.toJson(Socio::toStatic) << "}";
	return ss.str();
}

string Sesion::toStatic(Sesion* s)
{
	return s->toString();
}
