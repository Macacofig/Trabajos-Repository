#include "Jugador.h"

Jugador::Jugador(int ci, string nombre, int fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;
}

Jugador::~Jugador()
{
}

int Jugador::getCi()
{
	return ci;
}

string Jugador::getNombre()
{
	return nombre;
}

string Jugador::toString()
{
	stringstream ss;
	ss << "{\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\",\"fono\":" << fono << "}";
	return ss.str();
}

bool Jugador::CMPcC(Jugador* j1, Jugador* j2)
{
	return j1->getCi()>j2->getCi();
}

string Jugador::toStatic(Jugador* j)
{
	return j->toString();
}
