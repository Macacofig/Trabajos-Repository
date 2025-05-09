#include "Descarga.h"

Descarga::Descarga(int id, int megas, int fecha)
	:Accion(id,fecha,"descarga")
{
	this->megas = megas;
}

Descarga::~Descarga()
{
}

int Descarga::getMegas()
{
	return megas;
}

string Descarga::toJson()
{
	stringstream ss;
	ss << "{\"id\":" << id << ",\"fecha\":" << fecha << ",\"tipo\":\"" << tipo << "\"}";
	return ss.str();
}
