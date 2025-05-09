#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class ElementoGrafico
{
protected:
	int id;
	string tipo;
public:
	ElementoGrafico(int id,string tipo);
	~ElementoGrafico();
	int getId();
	string getTipo();
	virtual void dibujar() = 0;
	virtual void borrar() = 0;
};

