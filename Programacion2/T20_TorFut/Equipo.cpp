#include "Equipo.h"

Equipo::Equipo(string nombre)
{
	this->nombre = nombre;
}

Equipo::~Equipo()
{
}

ListaGen<Jugador>& Equipo::getJugadores()
{
	return jugadores;
}

string Equipo::getNombre()
{
	return nombre;
}

bool Equipo::operator==(Equipo* e)
{
	return nombre==e->getNombre();
}

bool Equipo::CMPnN(Equipo* e1, Equipo* e2)
{
	return e1->getNombre()<e2->getNombre();
}

string Equipo::toString()
{
	jugadores.ordenar(Jugador::CMPcC);
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre 
		<< "\",\"jugadores\":" << jugadores.toString(Jugador::toStatic) << "}";
	return ss.str();
}

string Equipo::toStatic(Equipo* e)
{
	return e->toString();
}

void Equipo::nuevoJugador(int ci, string nombre, int fono)
{
	jugadores.reggistrar(new Jugador(ci, nombre, fono));
}
