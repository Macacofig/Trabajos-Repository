#include "Torneo.h"

Torneo::Torneo()
{
}

Torneo::~Torneo()
{
}

ListaGen<Equipo>& Torneo::getEquipos()
{
	return equipos;
}

ListaGen<Partido>& Torneo::getPartidos()
{
	return partidos;
}

string Torneo::toString()
{
	equipos.ordenar(Equipo::CMPnN);
	stringstream ss;
	ss << "{\"equipos\":" << equipos.toString(Equipo::toStatic) << "}";
	return ss.str();
}
