#include "Texto.h"

Texto::Texto(long numero, string descripcion)
	:Mensaje(numero,"texto")
{
	this->descripcion=descripcion;
}

Texto::~Texto()
{
}

string Texto::toJson()
{
	stringstream ss;
	ss << "{\"autor\":" << numero << ",\"tipo\":\"" << tipo << "\",\"contenido\":\"" << descripcion << "\"}";
	return ss.str();
}
