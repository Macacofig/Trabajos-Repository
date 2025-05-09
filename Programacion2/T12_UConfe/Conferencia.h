#pragma once
#include "ModPersonas.h"
#include "Docente.h"
#include "Estudiante.h"
class Conferencia
{
protected:
	int numero;
	long fecha;
	ModPersonas instructores;
	ModPersonas participantes;
	string tipo;
public:
	Conferencia(int numero, long fecha,string tipo);
	~Conferencia();
	int getNumero();
	string getTipo();
	ModPersonas& getInstructores();
	ModPersonas& getParticipantes();
	void registrar(Estudiante* persona);
	void registrar(Docente* persona);
	virtual string toJson()=0;
};

