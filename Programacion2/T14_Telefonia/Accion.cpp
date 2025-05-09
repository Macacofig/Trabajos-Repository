#include "Accion.h"

Accion::Accion(string tipo, int id, long fecha)
{
	this->tipo = tipo;
	this->id = id;
	this->fecha = fecha;
}

Accion::~Accion()
{
}
