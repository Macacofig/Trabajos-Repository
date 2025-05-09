#pragma once
#include "Modpartidos.h" 
#include "ModEquiposInscritos.h"
#define CANT_MAX_EQINS 10
#define CANT_MAX_PAR 10
class Campeonato
{
private:
	string nombrecampeonato;
	string fechacampeonato;
	int codcampeonato;
	Modpartidos partidos;
	ModEquiposInscritos equiposinscritos;
public:
	//construct y destruc
	Campeonato(string nombrecampeonato,int codcampeonato,string fechacampeonato);
	~Campeonato();
	//gets y funciones
	string getnombrecampeonato();
	string getfechacampeonato();
	int getcodcampeonato();
	void mostrar();
	string toJson();
	//a partir de otras clases
	Modpartidos& getpartidos();
	ModEquiposInscritos& getequiposinscritos();

};

