#pragma once
#include "Sesion.h"
class ModSesiones
{
private:
	int ind;
	int tam;
	Sesion** sesiones;
public:
	ModSesiones(int tam);
	~ModSesiones();
	int getind();
	int gettam();
	void registrar(Sesion* sesion);
	Sesion* buscar(int idSesion);
	void mostrar();
	string toJson();
};

