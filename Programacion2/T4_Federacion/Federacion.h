#pragma once
#include "Modequipos.h"
#include "Modcampeonatos.h"
#include "Modjugadores.h"
#define CANT_MAX_EQ 10
#define CANT_MAX_CAM 10
#define CANT_MAX_JUG 100
class Federacion
{
private:
	string nombrefed;
	Modequipos equipos;
	Modcampeonatos campeonatos;
	Modjugadores jugadores;
public:
	//construc y destruc
	Federacion(string nombrefed);
	~Federacion();
	//gets y funciones
	string getnombrefed();
	void mostrar();
	string toJson();
	//funciones a partir de otra clase
	Modequipos& getequipos();
	Modcampeonatos& getcampeonatos();
	Modjugadores& getjugadores();

	void registarpartido(int codcampeonato,Partido* par);
	void inscribirequipo(int codcampeonato, int codequipo ,Equipo* equipo);
	void agregarJugEI(int codcampeonato, int ideqins, int ci);
	void agregarEILocal(int codcampeonato, int numpartido, int idequins);
	void agregarEIVisitante(int codcampeonato, int numpartido, int idequins);
};

