#pragma once
#include "Socio.h"
#include "ListaGen.h"
class Sesion
{
private:
	int fecha;
	ListaGen<Socio> socios;
public:
	Sesion(int fecha);
	~Sesion();
	int getFecha();
	ListaGen<Socio>& getSocios();
	bool operator==(Sesion* s);
	string toString();
	static string toStatic(Sesion* s);
};

