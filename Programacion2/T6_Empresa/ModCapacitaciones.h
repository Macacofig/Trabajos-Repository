#pragma once
#include "Capacitacion.h"

class ModCapacitaciones
{
private:
	int ind;
	int tam;
	Capacitacion** capacitaciones;
public:
	ModCapacitaciones(int tam);
	~ModCapacitaciones();
	int getind();
	int gettam();
	void registrar(Capacitacion* capacitacion);
	Capacitacion* buscar(int idCap);
	void mostrar();
	string toJson();
	void ordenar();
};

