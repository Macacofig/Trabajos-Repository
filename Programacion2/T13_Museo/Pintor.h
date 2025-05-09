#pragma once
#include "Artista.h"
class Pintor :public Artista
{
private:
	string especialidad;
public:
	Pintor(string nombre, string especialidad);
	~Pintor();
	string toJson();
};

