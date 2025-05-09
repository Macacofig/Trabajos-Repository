#include "Avion.h"

Avion::Avion(int placa, int filas, int columnas)
{
	this->placa = placa;
	this->filas = filas;
	this->columnas = columnas;
}

Avion::~Avion()
{
}

int Avion::getPlaca()
{
	return placa;
}

int Avion::getFilas()
{
	return filas;
}

int Avion::getColumnas()
{
	return columnas;
}

string Avion::toJson()
{
	stringstream ss;
	ss << "{\"placa\":"<<placa
	   <<",\"filas\":"<<filas
	   <<",\"columnas\":"<<columnas<<"}";
	return ss.str();
}
