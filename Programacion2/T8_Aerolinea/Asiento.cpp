#include "Asiento.h"

Asiento::Asiento(int fila, int columna)
{
	this->fila = fila;
	this->columna = columna;
	this->pasajero = NULL;
}

Asiento::~Asiento()
{
}

int Asiento::getFila()
{
	return fila;
}

int Asiento::getColumna()
{
	return columna;
}

string Asiento::toJson()
{
	stringstream ss;
	ss << "{\"fila\":" << fila;
	ss << ",\"columna\":" << columna;
	if (pasajero != NULL)
	{
		ss<< ",\"pasajero\":"<<pasajero->toJson()<<"}";
	}
	else
	{
		ss << ",\"pasajero\":\"vacio\"}";
	}
	return ss.str();
}

Persona* Asiento::getPasajero()
{
	return pasajero;
}

void Asiento::setPasajero(Persona* pasajero)
{
	this->pasajero = pasajero;
}
