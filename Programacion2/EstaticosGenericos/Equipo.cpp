#include "Equipo.h"

Equipo::Equipo(string nombre)
{
	this->nombre = nombre;
	id = GeneradorIds::getInst().getNextId();
}

Equipo::Equipo(string nombre, string descripcion)
{
	this->nombre = nombre;
	this->descripcion = descripcion;
	id = GeneradorIds::getInst().getNextId();
}

Equipo::~Equipo()
{
}

string Equipo::getNombre()
{
	return nombre;
}

string Equipo::getDescripcion()
{
	return descripcion;
}

string Equipo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"id\":" << id << ",";
	ss << "\"nombre\":\"" << nombre << "\",";
	ss << "\"descripcion\":\"" << descripcion;
	ss << "}";
	return ss.str();
}

bool Equipo::operator==(Equipo* e)
{
	return nombre == e->getNombre();
}

string Equipo::toJson(Equipo* e)
{
	return e->toJson();
}

bool Equipo::cmpNombreASC(Equipo* e1, Equipo* e2)
{
	return e1->getNombre() > e2->getNombre();
}

bool Equipo::cmpNombreDSC(Equipo* e1, Equipo* e2)
{
	return e1->getNombre() < e2->getNombre();
}

bool Equipo::cmpDescASC(Equipo* e1, Equipo* e2)
{
	return e1->getDescripcion() < e2->getDescripcion();
}

bool Equipo::cmpDescDSC(Equipo* e1, Equipo* e2)
{
	return e1->getDescripcion() < e2->getDescripcion();
}
