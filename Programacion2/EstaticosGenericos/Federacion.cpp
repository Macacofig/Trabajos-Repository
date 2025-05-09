#include "Federacion.h"

Federacion::Federacion(string nombre)
{
	this->nombre = nombre;
}

Federacion::~Federacion()
{
}

void Federacion::registrarEqiopo(string nombre, string descripcion)
{
	SingletonEquipos::getInst().getEquipos().registrar(new Equipo(nombre, descripcion));
}

string Federacion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"nombre\":\"" << nombre << "\",";
	ss << "\"equipos\":\"" << SingletonEquipos::getInst().getEquipos().toJson(Equipo::toJson);
	ss << "}";
	return ss.str();
}

void Federacion::mostrar()
{
	cout << "Federacion" << endl;
	cout << toJson();
}
