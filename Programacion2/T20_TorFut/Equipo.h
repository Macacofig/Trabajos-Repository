#pragma once
#include "Jugador.h"
#include "ListaGen.h"
class Equipo
{
private:
	string nombre;
	ListaGen<Jugador> jugadores;
public:
	Equipo(string nombre);
	~Equipo();
	ListaGen<Jugador>& getJugadores();
	string getNombre();
	bool operator==(Equipo* e);
	static bool CMPnN(Equipo* e1, Equipo* e2);
	string toString();
	static string toStatic(Equipo* e);
	void nuevoJugador(int ci, string nombre, int fono);
};

