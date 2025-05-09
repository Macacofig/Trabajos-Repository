#include "Pintor.h"

Pintor::Pintor(string nombre, string especialidad)
	:Artista(nombre)
{
	this->especialidad = especialidad;
}

Pintor::~Pintor()
{
}

string Pintor::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"especialidad\":\"" << especialidad
		<< "\",\"obras\":" << pinturas.toJson() << "}";
	return ss.str();
}
