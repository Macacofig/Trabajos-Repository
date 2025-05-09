#include "Accion.h"

Accion::Accion(int id, int fecha, string tipo)
{
	this->id = id;
	this->fecha = fecha;
	this->tipo = tipo;
}

Accion::~Accion()
{
}

string Accion::getTipo()
{
	return tipo;
}

string Accion::toJson()
{
	stringstream ss;
	return ss.str();
}

string Accion::toStatic(Accion* a)
{
	return a->toJson();
}

