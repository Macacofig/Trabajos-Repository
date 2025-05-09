#include "PaqueteMinutos.h"

PaqueteMinutos::PaqueteMinutos(int minutos)
	:Paquete("minutos")
{
	this->minutos = minutos;
}

PaqueteMinutos::~PaqueteMinutos()
{
}

int PaqueteMinutos::getMinutos()
{
	return minutos;
}

void PaqueteMinutos::setMinutos(int minutos)
{
	this->minutos = minutos;
}

string PaqueteMinutos::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"minutos\",\"saldo minutos\":"<<minutos<<"}";
	return ss.str();
}
