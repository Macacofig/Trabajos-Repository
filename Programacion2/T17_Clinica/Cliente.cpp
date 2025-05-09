#include "Cliente.h"


Cliente::Cliente(int ci, string nombre, int fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;
}

Cliente::Cliente(int ci)
{
	this->ci = ci;
}

Cliente::~Cliente()
{
}

bool Cliente::operator==(Cliente* c1)
{
	return ci==c1->getCi();
}

bool Cliente::cmpCIMm(Cliente* c1, Cliente* c2)
{
	return c1->getCi() < c2->getCi();
}

ListaGen<Mascota>& Cliente::getMascotas()
{
	return mascotas;
}

int Cliente::getCi()
{
	return ci;
}

string Cliente::toStatic(Cliente* c)
{
	return c->toJson();
}

string Cliente::toJson()
{
	stringstream ss;
	mascotas.ordenar(Mascota::CPNombre);
	ss << "{\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\",\"fono\":" << fono 
		<< ",\"mascotas\":"<<mascotas.toJson(Mascota::toStatic)<<"}";
	return ss.str();
}

string Cliente::toJsonB()
{
	stringstream ss;
	ss << "{\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\",\"fono\":" << fono << "}";
	return ss.str();
}
