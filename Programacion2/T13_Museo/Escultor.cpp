#include "Escultor.h"

Escultor::Escultor(string nombre, string materiales)
	:Artista(nombre)
{
	this->materiales = materiales;
}

Escultor::~Escultor()
{
}

string Escultor::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"materiales\":\"" << materiales
		<< "\",\"obras\":" << esculturas.toJson() << "}";
	return ss.str();
}
