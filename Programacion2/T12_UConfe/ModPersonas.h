#pragma once
#include "Persona.h"
#define PS 10
class ModPersonas
{
private:
	int ind;
	Persona** personas;
public:
	ModPersonas();
	~ModPersonas();
	void registrar(Persona* persona);
	Persona* buscar(string nombre);
	Persona* operator[](int pos);
	void operator<<(Persona* persona);
	void ordenar();
	string toJson();
};

