#include "Escultura.h"

Escultura::Escultura(string titulo, int precio, int peso)
	:Obra(titulo,precio)
{
	this->peso = peso;
}

Escultura::~Escultura()
{
}

string Escultura::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<titulo<<"\",\"precio\":"<<precio<<",\"peso\":"<<peso<<"}";
	return ss.str();
}
