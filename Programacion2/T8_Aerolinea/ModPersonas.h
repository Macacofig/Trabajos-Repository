#pragma once
#include "Persona.h"
class ModPersonas
{
private:
	int ind;
	int tam;
	Persona** personas;
public:
	ModPersonas(int tam);
	~ModPersonas();
	void registrar(Persona* persona);
	Persona* buscar(int ci);
	string toJson();
};

