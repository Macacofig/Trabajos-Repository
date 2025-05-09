#pragma once
#include "ListaGen.h"
#include "Equipo.h"
#include "Partido.h"

class Torneo
{
private:
	ListaGen<Equipo> equipos;
	ListaGen<Partido> partidos;
public:
	Torneo();
	~Torneo();
	ListaGen<Equipo>& getEquipos();
	ListaGen<Partido>& getPartidos();
	string toString();
};

