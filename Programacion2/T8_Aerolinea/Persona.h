#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Persona
{
private:
	int ci;
	string nombre;
	string direccion;
	int fono;
public:
	Persona(int ci, string nombre, string direccion, int fono);
	~Persona();
	int getCi();
	string toJson();
};

