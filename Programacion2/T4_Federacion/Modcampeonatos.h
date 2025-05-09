#pragma once
#include "Campeonato.h"
class Modcampeonatos
{
private:
	int ind;
	int tam;
	Campeonato** campeonatos;
public:
	Modcampeonatos(int tam);
	~Modcampeonatos();
	int getind();
	int gettam();
	void registrar(Campeonato* campeonato);
	Campeonato* buscar(int codcampeonato);
	void mostrar();
	string toJson();
};

