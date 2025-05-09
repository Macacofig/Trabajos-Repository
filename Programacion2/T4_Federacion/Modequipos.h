#pragma once
#include "Equipo.h"
class Modequipos
{
private:
	int ind;
	int tam;
	Equipo** equipos;
public:
	Modequipos(int tam);
	~Modequipos();
	int getind();
	int gettam();
	void registrareq(Equipo* equipo);
	Equipo* buscar(int codequipo);
	void mostrar();
	string toJson();
};

