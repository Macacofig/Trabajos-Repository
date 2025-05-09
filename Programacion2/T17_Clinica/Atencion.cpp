#include "Atencion.h"

Atencion::Atencion(int codigo)
{
	this->codigo=codigo;
}

Atencion::Atencion(int codigo, string descripcion, int costo)
{
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->costo = costo;
}

Atencion::~Atencion()
{
}

int Atencion::getCodigo()
{
	return codigo;
}

bool Atencion::operator==(Atencion* a)
{
	return codigo==a->getCodigo();
}

bool Atencion::CMPmM(Atencion* a1, Atencion* a2)
{
	return a1->getCodigo() > a2->getCodigo();
}

string Atencion::toJson()
{
	stringstream ss;
	return ss.str();
}

string Atencion::toStatic(Atencion* at)
{
	return at->toJson();
}
