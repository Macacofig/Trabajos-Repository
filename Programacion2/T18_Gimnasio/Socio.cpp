#include "Socio.h"

Socio::Socio(int ci, string nombre)
{
	this->ci = ci;
	this->nombre = nombre;
}

Socio::Socio(int ci)
{
	this->ci = ci;
}

Socio::~Socio()
{
}

int Socio::getCi()
{
	return ci;
}

string Socio::getNombre()
{
	return nombre;
}

string Socio::toJson()
{
	stringstream ss;
	ss << "{\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\"}";
	return ss.str();
}

bool Socio::operator==(Socio* s)
{
	return ci == s->getCi();
}

bool Socio::OrAC(Socio* s1, Socio* s2)
{
	return s1->getNombre()>s2->getNombre();
}

string Socio::toStatic(Socio* s)
{
	return s->toJson();
}
