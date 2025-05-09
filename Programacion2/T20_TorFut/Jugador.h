#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Jugador
{
private:
	int ci;
	string nombre;
	int fono;
public:
	Jugador(int ci, string nombre, int fono);
	~Jugador();
	int getCi();
	string getNombre();
	string toString();
	static bool CMPcC(Jugador* j1,Jugador* j2);
	static string toStatic(Jugador* j);
};


