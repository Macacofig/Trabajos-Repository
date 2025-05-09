#include "AutoNoDeportivo.h"

AutoNoDeportivo::AutoNoDeportivo(string patente, string marca, int modelo, int km, string FechaImportacion)
	:Vehiculo(patente, marca, modelo, km)
{
	this->FechaImportacion = FechaImportacion;
}

AutoNoDeportivo::~AutoNoDeportivo()
{
}

string AutoNoDeportivo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"vehiculo\":\"AutoDeportivo \",";
	ss << "\"Fecha de Importacion\":\"" << FechaImportacion << "\",";
	ss << "\"Base\":" << Vehiculo::toJson();
	ss << "}";
	return ss.str();
}
