#include "Llamada.h"

Llamada::Llamada(int id, int fecha, int durmin)
	:Accion(id,fecha,"llamada")
{
	this->durmin = durmin;
}

Llamada::~Llamada()
{
}

int Llamada::getDurmin()
{
	return durmin;
}

string Llamada::toJson()
{
	stringstream ss;
	ss << "{\"id\":" << id << ",\"fecha\":" << fecha << ",\"minutos\":" << durmin << ",\"tipo\":\"" << tipo << "\"}";
	return ss.str();
}
