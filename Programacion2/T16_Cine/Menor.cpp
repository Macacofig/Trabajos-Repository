#include "Menor.h"

Menor::Menor(int ci, string nombre)
	:Cliente(ci, nombre, "menor")
{
}

Menor::~Menor()
{
}

string Menor::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"" << tipo << "\",\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\"}";
	return ss.str();
}
