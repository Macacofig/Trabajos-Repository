#include "ElementoGrafico.h"

ElementoGrafico::ElementoGrafico(int id,string tipo)
{
	this->id = id;
	this->tipo = tipo;
}

ElementoGrafico::~ElementoGrafico()
{
}

int ElementoGrafico::getId()
{
	return id;
}

string ElementoGrafico::getTipo()
{
	return tipo;
}
