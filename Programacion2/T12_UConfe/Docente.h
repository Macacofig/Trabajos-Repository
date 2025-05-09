#pragma once
#include "Persona.h"
class Docente :public Persona
{
private:
	string especialidad;
public:
	Docente(string nombre, string especialidad);
	~Docente();
	string toJson();
};

