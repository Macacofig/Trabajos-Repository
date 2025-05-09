#include "Museo.h"

Museo::Museo(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Museo::~Museo()
{
}

ModExposiciones& Museo::getExposiciones()
{
	return exposiciones;
}

void Museo::registrarExposicion(int numero)
{
	exposiciones.registrar(new Exposicion(numero));
}

void Museo::registrarArtistaEnExposicion(int numero, Pintor* pintor)
{
	Exposicion* e = exposiciones.buscar(numero);
	if (e != NULL)
	{
		e->getArtistas().registrar(pintor);
	}
}

void Museo::registrarArtistaEnExposicion(int numero, Escultor* escultor)
{
	Exposicion* e = exposiciones.buscar(numero);
	if (e != NULL)
	{
		e->getArtistas().registrar(escultor);
	}
}

void Museo::registrarObraEnExposicion(int numero, string nombre, Escultura* escultura)
{
	Exposicion* e = exposiciones.buscar(numero);
	if (e != NULL)
	{
		e->registrarEsculturaArtista(nombre, escultura);
	}
}

void Museo::registrarObraEnExposicion(int numero, string nombre, Pintura* pintura)
{
	Exposicion* e = exposiciones.buscar(numero);
	if (e != NULL)
	{
		e->registrarPinturaArtista(nombre, pintura);
	}
}

string Museo::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"dirreccion\":\"" << direccion << "\",\"exposiciones\":" << exposiciones.toJson() << "}";
	return ss.str();
}
