#include "Artista.h"

Artista::Artista(string nombre)
{
	this->nombre = nombre;
}

Artista::~Artista()
{
}

string Artista::getNombre()
{
	return nombre;
}

ModObras& Artista::getPinturas()
{
	return pinturas;
}

ModObras& Artista::getEsculturas()
{
	return esculturas;
}

void Artista::registrar(Pintura* pintura)
{
	pinturas.registrar(pintura);
}

void Artista::registrar(Escultura* escultura)
{
	esculturas.registrar(escultura);
}

string Artista::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\"}";
	return ss.str();
}
