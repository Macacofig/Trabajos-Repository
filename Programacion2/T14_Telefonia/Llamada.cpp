#include "Llamada.h"

Llamada::Llamada(int id, long fecha, int durmin)
	:Accion("llamada",id,fecha)
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
	ss << "{\"id\":" << id << ",\"fecha\":" << fecha << ",\"minutos\":" << durmin << ",\"tipo\":\"llamada\"}";
	return ss.str();
}
