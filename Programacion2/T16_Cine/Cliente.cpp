#include "Cliente.h"

Cliente::Cliente(int ci, string nombre, string tipo)
{
	this->ci = ci;
	this->nombre = nombre;
	this->tipo = tipo;
}

Cliente::Cliente(int ci)
{
	this->ci = ci;
}

Cliente::~Cliente()
{
}

int Cliente::getCi()
{
	return ci;
}

string Cliente::toString()
{
	stringstream ss;
	return ss.str();
}

string Cliente::toStatic(Cliente* c)
{
	return c->toString();
}

bool Cliente::operator==(Cliente* c)
{
	return ci==c->getCi();
}


