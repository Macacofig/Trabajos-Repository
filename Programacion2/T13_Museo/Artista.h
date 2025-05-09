#pragma once
#include "ModObras.h"
#include "Escultura.h"
#include "Pintura.h"
class Artista
{
protected:
	string nombre;
	ModObras pinturas;
	ModObras esculturas;
public:
	Artista(string nombre);
	~Artista();
	string getNombre();
	ModObras& getPinturas();
	ModObras& getEsculturas();
	void registrar(Pintura* pintura);
	void registrar(Escultura* escultura);
	virtual string toJson();
};

