#include "Persona.h"

Persona::Persona(string nombre,string tipo)
{
	this->nombre = nombre;
	this->tipo = tipo;
}

Persona::~Persona()
{
}

string Persona::getTipo()
{
	return tipo;
}

string Persona::getNombre()
{
	return nombre;
}

bool Persona::operator>(Persona& p)
{
	if (nombre > p.nombre)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Persona::operator==(Persona& p)
{
	if (nombre == p.nombre)
	{
		return true;
	}
	else
	{
		return false;
	}
}
