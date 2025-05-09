#include "Partido.h"

Partido::Partido(int numpartido,EquipoInscrito* local, EquipoInscrito* visitante)
{
	this->numpartido = numpartido;
	this->local = local;
	this->visitante = visitante;
}

Partido::~Partido()
{
}

int Partido::getnumpartido()
{
	return numpartido;
}

string Partido::getfechapartido()
{
	return fechapartido;
}

void Partido::mostrar()
{
	cout << "Partido:" << endl;
	cout << toJson() << endl;
}

string Partido::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"NumeroPartido\":" << numpartido << ",";
	ss << "\"EquipoLocal\":" << local->toJson();
	ss << "\"EquipoVisitante\":" << visitante->toJson();
	ss << "}";
	return ss.str();
}

EquipoInscrito& Partido::getlocal()
{
	return *local;
}

EquipoInscrito& Partido::getvisitante()
{
	return *visitante;
}
