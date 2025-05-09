#pragma once
#include "EquipoInscrito.h"
class Partido
{
private:
	int numpartido;
	string fechapartido;
	EquipoInscrito* local;
	EquipoInscrito* visitante;
public:
	Partido(int numpartido,EquipoInscrito* local,EquipoInscrito* visitante);
	~Partido();

	int getnumpartido();
	string getfechapartido();
	void mostrar();
	string toJson();

	EquipoInscrito& getlocal();
	EquipoInscrito& getvisitante();

};

