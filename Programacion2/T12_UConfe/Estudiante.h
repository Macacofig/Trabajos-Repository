#pragma once
#include "Persona.h"
class Estudiante :public Persona
{
private:
	string carrera;
public:
	Estudiante(string nombre, string carrera);
	~Estudiante();
	string toJson();
};

