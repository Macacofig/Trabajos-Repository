#include "Indeception.h"

Indeception::Indeception(string nom)
{
	stringstream ss;
	ss << "Equipo " << nom << " inexsistente";
	mensaje = ss.str();
}

Indeception::~Indeception()
{
}

const char* Indeception::what() const
{
	return mensaje.c_str();
}
