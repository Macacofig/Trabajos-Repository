#include "Jugador.h"

Jugador::Jugador()
{
}

Jugador::Jugador(int ci, string nombre, string genero)
{
	this->ci = ci;
	this->nombre = nombre;
	this->genero = genero;
}

Jugador::~Jugador()
{
}

int Jugador::getci()
{
	return ci;
}

string Jugador::getnombre()
{
	return nombre;
}

string Jugador::getgenero()
{
	return genero;
}

void Jugador::mostrar()
{
	cout << "Jugador:" << endl;
	cout << toJson() << endl;
}

string Jugador::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"ci\":" << ci << ",";
	ss << "\"nombre\":\"" << nombre << "\",";
	ss << "\"genero\":\"" << genero << "\",";
	ss << "}";
	return ss.str();
}
