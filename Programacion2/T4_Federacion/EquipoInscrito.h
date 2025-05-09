#pragma once
#include "Modjugadores.h"
#include "Equipo.h"
#define CANT_MAX_JUGA 15
class EquipoInscrito
{
private:
	int ideqins;
	Modjugadores jugadores;
	Equipo* equipo;
public:
	//construc y destruc
	EquipoInscrito(int ideqins,Equipo* equipo);
	~EquipoInscrito();
	//gets y funciones
	int getideqins();
	void mostrar();
	string toJson();
	//funciones a partir de clases
	Modjugadores& getjugadores();
	Equipo* getequipo();
};

