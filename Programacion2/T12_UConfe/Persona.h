#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Persona
{
protected:
	string nombre;
	string tipo;
public:
	Persona(string nombre,string tipo);
	~Persona();
	string getTipo();
	string getNombre();
	virtual string toJson()=0;
	bool operator>(Persona& p);
	bool operator==(Persona& p);
};

