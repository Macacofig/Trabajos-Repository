#include "Mensaje.h"

Mensaje::Mensaje(long numero, string tipo)
{
	this->numero = numero;
	this->tipo = tipo;
}

long Mensaje::getNumero()
{
	return numero;
}

Mensaje::~Mensaje()
{
}

string Mensaje::toJsonStatic(Mensaje* m)
{
	return m->toJson();
}
