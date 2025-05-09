#pragma once
#include "Equipo.h"
class Partido
{
private:
	int id;
	Equipo* local;
	Equipo* visitante;
public:
	Partido(int id, Equipo* local, Equipo* visitante);
	~Partido();
	string toString();
	static string toStatic();
};

