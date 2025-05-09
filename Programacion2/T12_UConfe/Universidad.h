#pragma once
#include "ConferenciaPresencial.h"
#include "Docente.h"
#include "Estudiante.h"
#include "ConferenciaVirtual.h"
#include "ModConferencias.h"
#include "ModPersonas.h"
class Universidad
{
private:
	string nombre;
	string direccion;
	ModConferencias conferencias;
	ModPersonas personas;
public:
	Universidad(string nombre, string direccion);
	~Universidad();
	void registrarConferenciaVirtual(int numero, int fecha, string link);
	void registrarConferenciaPresencial(int numero, int fecha, string lugar);
	void registrarParticipanteEnConferencia(int numero, Docente* docente);
	void registrarParticipanteEnConferencia(int numero, Estudiante* estudiante);
	string toJson();
};

