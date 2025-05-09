#include "Mascota.h"

Mascota::Mascota(string nombre, int edad)
{
	this->nombre = nombre;
	this->edad = edad;
}

Mascota::~Mascota()
{
}

string Mascota::getNombre()
{
	return nombre;
}

int Mascota::getEdad()
{
	return edad;
}

string Mascota::toString()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"edad\":" << edad << "}";
	return ss.str();
}
