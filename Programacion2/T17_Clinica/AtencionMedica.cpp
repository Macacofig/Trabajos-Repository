#include "AtencionMedica.h"

AtencionMedica::AtencionMedica(int codigo)
	:Atencion(codigo)
{
}

AtencionMedica::AtencionMedica(int codigo, string descripcion, int costo, string medicamentos)
	:Atencion(codigo,descripcion,costo)
{
	this->medicamentos = medicamentos;
}

AtencionMedica::~AtencionMedica()
{
}

string AtencionMedica::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"AtencionMedica\",\"codigo\":" << codigo << ",\"descripcion\":\"" << descripcion
		<< "\",\"costo\":" << costo << ",\"medicamentos\":\"" << medicamentos << "\"}";
	return ss.str();
}
