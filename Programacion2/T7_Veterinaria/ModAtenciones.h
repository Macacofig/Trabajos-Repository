#pragma once
#include "Atencion.h"
class ModAtenciones
{
private:
	int ind;
	int tam;
	Atencion** atenciones;
public:
	ModAtenciones(int tam);
	~ModAtenciones();
	void registar(Atencion* atencion);
	Atencion* buscar(int codigo);
	string toString();
	void ordenar();
};

