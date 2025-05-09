#include "Paquete.h"

Paquete::Paquete(string tipo)
{
	this->tipo = tipo;
}

Paquete::~Paquete()
{
}

string Paquete::getTipo()
{
	return tipo;
}
