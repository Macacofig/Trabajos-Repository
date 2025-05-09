#include "Moto.h"

Moto::Moto(string patente, string marca, int modelo, int km, string tipo)
	:Vehiculo(patente,marca,modelo,km)
{
	this->tipo = tipo;
}

Moto::~Moto()
{
}

string Moto::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"vehiculo\":\"moto \",";
	ss << "\"Modelo\":\"" << tipo << "\",";
	ss<< "\"Base\":" << Vehiculo::toJson();
	ss << "}";
	return ss.str();
}
