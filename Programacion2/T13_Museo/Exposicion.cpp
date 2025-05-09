#include "Exposicion.h"

Exposicion::Exposicion(int numero)
{
	this->numero = numero;
}

Exposicion::~Exposicion()
{
}

ModArtistas& Exposicion::getArtistas()
{
	return artistas;
}
int Exposicion::getNumero()
{
	return numero;
}
void Exposicion::registrar(Pintor* pintor)
{
	artistas.registrar(pintor);
}

void Exposicion::registrar(Escultor* escultor)
{
	artistas.registrar(escultor);
}

void Exposicion::registrar(Artista* artista)
{
	artistas.registrar(artista);
}

void Exposicion::registrarPinturaArtista(string nombre, Pintura* pintura)
{
	Artista* a = artistas.buscar(nombre);
	if (a != NULL)
	{
		a->getPinturas().registrar(pintura);
	}
}

void Exposicion::registrarEsculturaArtista(string nombre, Escultura* escultura)
{
	Artista* a = artistas.buscar(nombre);
	if (a != NULL)
	{
		a->getEsculturas().registrar(escultura);
	}
}

string Exposicion::toJson()
{
	stringstream ss;
	ss << "{\"numero\":"<<numero
		<<",\"artistas\":"<<artistas.toJson()<<"}";
	return ss.str();
}
