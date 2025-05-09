#pragma once
#include "Jugador.h"
class Modjugadores
{
private:
	int ind;
	int tam;
	Jugador** jugadores;
public:
	Modjugadores(int tam);
	~Modjugadores();
	int getind();
	int gettam();
	void registrarju(Jugador* jugador);
	Jugador* buscar(int ci);
	void mostrar();
	string toJson();
};

