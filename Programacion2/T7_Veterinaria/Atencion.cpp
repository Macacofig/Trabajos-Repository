#include "Atencion.h"

Atencion::Atencion(int codigo, string descripcion, int costo, string detalle)
{
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->costo = costo;
	this->detalle = detalle;
}

Atencion::~Atencion()
{
}

int Atencion::getCodigo()
{
	return codigo;
}

string Atencion::toString()
{
	stringstream ss;
	ss << "{\"codigo\":"<<codigo<<",\"descripcion\":\""<<descripcion<<"\",\"costo\":"<<costo<<",\"detalle\":\""<<detalle<<"\"}";
	return ss.str();
}

