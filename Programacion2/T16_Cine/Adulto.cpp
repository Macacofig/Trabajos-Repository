#include "Adulto.h"

Adulto::Adulto(int ci, string nombre)
	:Cliente(ci,nombre,"adulto")
{
}

Adulto::~Adulto()
{
}

string Adulto::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"" << tipo << "\",\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\"}";
	return ss.str();
}
