#include "Estudiante.h"

Estudiante::Estudiante(string nombre, string carrera)
	:Persona(nombre,"Estudiante")
{
	this->carrera = carrera;
}

Estudiante::~Estudiante()
{
}

string Estudiante::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"carrera\":\""<<carrera<<"\"}";
	return ss.str();
}
