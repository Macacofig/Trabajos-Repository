#pragma once
#include "Socio.h"
#include "ListaGen.h"
class SingletonSocios
{
private:
	ListaGen<Socio>* socios;
public:
	static SingletonSocios& getInst();
	~SingletonSocios();
	ListaGen<Socio>*& getSocios();
	string toString();
private:
	SingletonSocios();
};

