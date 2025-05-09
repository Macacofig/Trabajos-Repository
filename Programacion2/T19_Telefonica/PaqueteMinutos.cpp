#include "PaqueteMinutos.h"

PaqueteMinutos::PaqueteMinutos(int saldo)
	:Paquete(saldo,"minutos")
{
}

PaqueteMinutos::~PaqueteMinutos()
{
}

string PaqueteMinutos::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"" << tipo << "\",\"saldo minutos\":" << saldo << "}";
	return ss.str();
}
