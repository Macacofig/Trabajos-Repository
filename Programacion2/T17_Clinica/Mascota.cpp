#include "Mascota.h"

Mascota::Mascota(string nombre)
{
	this->nombre = nombre;
}

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

bool Mascota::operator==(Mascota* m)
{
	return nombre==m->getNombre();
}

bool Mascota::CPNombre(Mascota* m1, Mascota* m2)
{
	return m1->getNombre()>m2->getNombre();
}

string Mascota::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"edad\":" << edad << "}";
	return ss.str();
}

string Mascota::toStatic(Mascota* m)
{
	return m->toJson();
}
