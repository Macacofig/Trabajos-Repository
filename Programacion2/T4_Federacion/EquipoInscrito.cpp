#include "EquipoInscrito.h"

EquipoInscrito::EquipoInscrito(int ideqins,Equipo* equipo)
	:jugadores(CANT_MAX_JUGA)
{
	this->ideqins = ideqins;
	this->equipo = equipo;
}

EquipoInscrito::~EquipoInscrito()
{
}

int EquipoInscrito::getideqins()
{
	return ideqins;
}

Modjugadores& EquipoInscrito::getjugadores()
{
	return jugadores;
}

Equipo* EquipoInscrito::getequipo()
{
	return equipo;
}

void EquipoInscrito::mostrar()
{
	cout << "EquipoInscrito:" << endl;
	cout << toJson() << endl;
}

string EquipoInscrito::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"NumEquipoInscrito\":" << ideqins << ",";
	ss << "\"Equipo:\":" << equipo->toJson();
	ss << "\"jugadores\":" << jugadores.toJson();
	ss << "}";
	return ss.str();
}


