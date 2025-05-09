#pragma once
#include "Equipo.h"
#include "ListaGen.h"
class SingletonEquipos
{
private:
	ListaGen<Equipo> equipos;
public:
	static SingletonEquipos& getInst();
	~SingletonEquipos();
	ListaGen<Equipo>& getEquipos();
private:
	SingletonEquipos();
};

