#include "ModArtistas.h"

ModArtistas::ModArtistas()
{
	ind = 0;
	artistas = new Artista * [AS];
}

ModArtistas::~ModArtistas()
{
	delete[] artistas;
}

Artista* ModArtistas::buscar(string nombre)
{
	for (int i = 0; i < ind; i++)
	{
		if (artistas[i]->getNombre() == nombre)
		{
			return artistas[i];
		}
	}
	return NULL;
}

void ModArtistas::registrar(Artista* artista)
{
	if (ind < AS)
	{
		artistas[ind] = artista;
		ind++;
	}
}

string ModArtistas::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << artistas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
