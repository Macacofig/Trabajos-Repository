#include "PaqueteMegas.h"

PaqueteMegas::PaqueteMegas(int saldo)
	:Paquete(saldo, "megas")
{
}

PaqueteMegas::~PaqueteMegas()
{
}

string PaqueteMegas::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"" << tipo << "\",\"saldo megas\":" << saldo << "}";
	return ss.str();
}