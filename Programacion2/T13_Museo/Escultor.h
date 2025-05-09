#pragma once
#include "Artista.h"
class Escultor :public Artista
{
private:
	string materiales;
public:
	Escultor(string nombre, string materiales);
	~Escultor();
	string toJson();
};

