#pragma once
#include "EquipoInscrito.h"

class ModEquiposInscritos
{
private:
	int ind;
	int tam;
	EquipoInscrito** equiposinscritos;
public:
	ModEquiposInscritos(int tam);
	~ModEquiposInscritos();
	int getind();
	int gettam();
	void registrar(EquipoInscrito* equipoinscrito);
	EquipoInscrito* buscar(int ideqins);
	void mostrar();
	string toJson();
};

