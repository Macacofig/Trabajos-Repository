#include "Federacion.h"

Federacion::Federacion(string nombrefed) 
	:equipos(CANT_MAX_EQ),campeonatos(CANT_MAX_CAM), jugadores(CANT_MAX_JUG)
{
	this->nombrefed = nombrefed;
}

Federacion::~Federacion()
{
}

string Federacion::getnombrefed()
{
	return string();
}

Modequipos& Federacion::getequipos()
{
	return equipos;
}

Modcampeonatos& Federacion::getcampeonatos()
{
	return campeonatos;
}

Modjugadores& Federacion::getjugadores()
{
	return jugadores;
}

void Federacion::registarpartido(int codcampeonato, Partido* par)
{
	Campeonato* campeonato = campeonatos.buscar(codcampeonato);
	if (campeonato != NULL)
	{
		campeonato->getpartidos().registrar(par);
	}
	else
	{
		cout << "Codigo de campeonato invalido";
	}
}

void Federacion::mostrar()
{
	cout << "Federacion:"<<endl;
	cout << toJson() << endl;
}

string Federacion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"nombrefed\":\"" << nombrefed << "\",";
	ss << "\"equipos\":" << equipos.toJson();
	ss << "\"campeonatos\":" << campeonatos.toJson();
	ss << "\"jugadores\":" << jugadores.toJson();
	ss << "}";
	return ss.str();
}
