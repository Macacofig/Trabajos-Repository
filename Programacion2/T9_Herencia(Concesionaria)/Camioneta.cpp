#include "Camioneta.h"

Camioneta::Camioneta(string patente, string marca, int modelo, int km, int CapCarga)
	:Vehiculo(patente,marca,modelo,km)
{
	this->CapCarga = CapCarga;
}

Camioneta::~Camioneta()
{
}

string Camioneta::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"vehiculo\":\"camioneta \",";
	ss << "\"Capacidad_Carga\":" << CapCarga << ",";
	ss << "\"Base\":" << Vehiculo::toJson();
	ss << "}";
	return ss.str();
}
