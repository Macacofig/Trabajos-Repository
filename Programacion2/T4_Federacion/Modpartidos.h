#pragma once
#include "Partido.h"
class Modpartidos
{
private:
	int ind;
	int tam;
	Partido** partidos;
public:
	Modpartidos(int tam);
	~Modpartidos();
	int getind();
	int gettam();
	void registrar(Partido* partido);
	Partido* buscar(int numpartido);
	void mostrar();
	string toJson();
};

