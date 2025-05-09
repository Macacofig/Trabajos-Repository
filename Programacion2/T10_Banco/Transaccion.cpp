#include "Transaccion.h"

Transaccion::Transaccion(int id, string Fecha, string Hora, int monto, string tipo)
{
	this->id = id;
	this->Fecha = Fecha;
	this->Hora = Hora;
	this->monto = monto;
	this->tipo = tipo;
}

Transaccion::~Transaccion()
{
}

int Transaccion::getMonto()
{
	return monto;
}

int Transaccion::getId()
{
	return id;
}

string Transaccion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss << "\"Fecha\":\"" << Fecha << "\",";
	ss << "\"Hora\":" << Hora << "\",";
	ss << "\"Monto\":" << monto << ",";
	ss << "\"Tipo\":\"" << tipo<<"\"";
	ss << "}";
	return ss.str();
}
