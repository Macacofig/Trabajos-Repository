#include "Cuenta.h"

Cuenta::Cuenta(int id, int saldo)
{
	this->id = id;
	this->saldo = saldo;
}

Cuenta::~Cuenta()
{
}

int Cuenta::getId()
{
	return id;
}

int Cuenta::getSaldo()
{
	return saldo;
}

ModTransacciones& Cuenta::getTransacciones()
{
	return transacciones;
}

string Cuenta::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss<< "\"Saldo\":" << saldo<<",";
	ss << "\"Transacciones\":" << transacciones.toJson();
	ss << "}";
	return ss.str();
}
