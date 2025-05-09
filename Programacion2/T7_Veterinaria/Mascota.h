#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Mascota
{
private:
	string nombre;
	int edad;
public:
	Mascota(string nombre, int edad);
	~Mascota();
	string getNombre();
	int getEdad();
	string toString();
};

