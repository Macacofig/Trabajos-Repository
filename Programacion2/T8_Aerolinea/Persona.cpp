#include "Persona.h"

Persona::Persona(int ci, string nombre, string direccion, int fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->direccion = direccion;
	this->fono = fono;
}

Persona::~Persona()
{
}

int Persona::getCi()
{
	return ci;
}

string Persona::toJson()
{
	stringstream ss;
	ss << "{\"ci\":"<<ci<<",\"nombre\":\""<<nombre<<"\",\"direccion\":\""<<direccion<<"\",\"fono\":"<<fono<<"}";
	return ss.str();
}
