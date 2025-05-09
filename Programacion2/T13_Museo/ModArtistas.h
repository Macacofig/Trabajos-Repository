#pragma once
#include "Artista.h"
#define AS 10
class ModArtistas
{
private:
	int ind;
	Artista** artistas;
public:
	ModArtistas();
	~ModArtistas();
	Artista* buscar(string nombre);
	void registrar(Artista* artista);
	string toJson();
};

