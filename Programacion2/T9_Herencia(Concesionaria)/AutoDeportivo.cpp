#include "AutoDeportivo.h"

AutoDeportivo::AutoDeportivo(string patente, string marca, int modelo, int km, string PaisOrigen)
	:Vehiculo(patente, marca, modelo, km)
{
	this->PaisOrigen = PaisOrigen;
}

AutoDeportivo::~AutoDeportivo()
{
}

string AutoDeportivo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"vehiculo\":\"AutoDeportivo \",";
	ss << "\"Pais de Origen\":\"" << PaisOrigen << "\",";
	ss << "\"Base\":" << Vehiculo::toJson();
	ss << "}";
	return ss.str();
}
