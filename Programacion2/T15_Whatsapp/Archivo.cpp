#include "Archivo.h"

Archivo::Archivo(long numero, string nombre, string ext)
	:Mensaje(numero,"archivo")
{
	this->nombre = nombre;
	this->ext = ext;
}

Archivo::~Archivo()
{
}

string Archivo::toJson()
{
	stringstream ss;
	ss << "{\"autor\":" << numero << ",\"tipo\":\"" << tipo << "\",\"nombre\":\"" << nombre << "\",\"ext\":\"" << ext << "\"}";
	return ss.str();
}
