#include "AtencionPeluqueria.h"

AtencionPeluqueria::AtencionPeluqueria(int codigo)
	:Atencion(codigo)
{
}

AtencionPeluqueria::AtencionPeluqueria(int codigo, string descripcion, int costo, int DurMinutos)
	:Atencion(codigo, descripcion, costo)
{
	this->DurMinutos = DurMinutos;
}

AtencionPeluqueria::~AtencionPeluqueria()
{
}

string AtencionPeluqueria::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"AtencionPeluqueria\",\"codigo\":" << codigo << ",\"descripcion\":\"" << descripcion
		<< "\",\"costo\":" << costo << ",\"duracion\":" << DurMinutos << "}";
	return ss.str();
}
