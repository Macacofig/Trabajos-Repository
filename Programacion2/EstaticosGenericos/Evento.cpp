#include "Evento.h"

Evento::Evento(int minuto, string tipo)
{
	this->minuto = minuto;
	this->tipo = tipo;
	id = GeneradorIds::getInst().getNextId();
}

Evento::~Evento()
{
}

string Evento::toJson()
{
	stringstream ss;
	ss << "\"id\":" << id << ",";
	ss << "\"minuto\":" << minuto << ",";
	ss << "\"tipo\":\"" << tipo << "\"";
	return ss.str();
}

string Evento::toJson(Evento* e)
{
	return e->toJson();
}
