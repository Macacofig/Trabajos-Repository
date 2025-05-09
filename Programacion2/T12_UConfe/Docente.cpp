#include "Docente.h"

Docente::Docente(string nombre, string especialidad)
	:Persona(nombre,"Docente")
{
	this->especialidad = especialidad;
}

Docente::~Docente()
{
}

string Docente::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"especialidad\":\"" << especialidad << "\"}";
	return ss.str();
}
