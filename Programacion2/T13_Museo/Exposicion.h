#pragma once
#include "ModArtistas.h"
#include "Pintor.h"
#include "Escultor.h"
class Exposicion
{
private:
	int numero;
	ModArtistas artistas;
public:
	Exposicion(int numero);
	~Exposicion();
	ModArtistas& getArtistas();
	int getNumero();
	void registrar(Pintor* pintor);
	void registrar(Escultor* escultor);
	void registrar(Artista* artista);
	void registrarPinturaArtista(string nombre, Pintura* pintura);
	void registrarEsculturaArtista(string nombre, Escultura* escultura);
	string toJson();
};

