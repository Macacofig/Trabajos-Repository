#include "Pintura.h"

Pintura::Pintura(string titulo, int precio, int alto, int ancho)
	:Obra(titulo,precio)
{
	this->alto = alto;
	this->ancho = ancho;
}

Pintura::~Pintura()
{
}

string Pintura::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << titulo << "\",\"precio\":" << precio 
		<< ",\"alto\":" << alto << ",\"ancho\":" << ancho << "}";
	return ss.str();
}
