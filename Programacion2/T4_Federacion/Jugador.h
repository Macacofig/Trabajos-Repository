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
	string genero;
public:
	//Const
	Jugador();
	Jugador(int ci, string nombre, string genero);
	//Des
	~Jugador();
	//gets
	int getci();
	string getnombre();
	string getgenero();
	//another
	void mostrar();
	string toJson();
};

