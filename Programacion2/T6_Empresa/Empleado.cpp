#include "Empleado.h"

Empleado::Empleado()
{
}

Empleado::Empleado(int Ci, string Nombre, string AreaEspe, int Aniostrabajo)
{
	this->Ci = Ci;
	this->Nombre = Nombre;
	this->AreaEspe = AreaEspe;
	this->Aniostrabajo = Aniostrabajo;
}

Empleado::~Empleado()
{
}

int Empleado::getCi()
{
	return Ci;
}

string Empleado::getNombre()
{
	return Nombre;
}

string Empleado::getAreaEspe()
{
	return AreaEspe;
}

int Empleado::getAniostrabajo() 
{
	return Aniostrabajo;
}

void Empleado::setCi(int Ci)
{
	this->Ci = Ci;
}

void Empleado::setNombre(string Nombre)
{
	this->Nombre = Nombre;
}

void Empleado::setAreaEspe(string AreaEspe)
{
	this->AreaEspe = AreaEspe;
}

void Empleado::setAniostrabajo(int Aniostrabajo)
{
	this->Aniostrabajo = Aniostrabajo;
}

void Empleado::mostrar()
{
	cout << "Empleado:" << endl;
	cout << toJson();
}

string Empleado::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Ci\":" << Ci << ",";
	ss << "\"Nombre\":\"" << Nombre << "\", ";
	ss << "\"AreaEspecializacion\":\"" << AreaEspe << "\",";
	ss << "\"Aniostranajo\":" << Aniostrabajo;
	ss << "}";
	return ss.str();
}
