#include "Conferencia.h"

Conferencia::Conferencia(int numero, long fecha,string tipo)
{
	this->numero = numero;
	this->fecha = fecha;
	this->tipo = tipo;
}

Conferencia::~Conferencia()
{
}

int Conferencia::getNumero()
{
	return numero;
}

string Conferencia::getTipo()
{
	return tipo;
}

ModPersonas& Conferencia::getInstructores()
{
	return instructores;
}

ModPersonas& Conferencia::getParticipantes()
{
	return participantes;
}

void Conferencia::registrar(Estudiante* persona)
{
	participantes.registrar(persona);
}

void Conferencia::registrar(Docente* persona)
{
	instructores.registrar(persona);
}
