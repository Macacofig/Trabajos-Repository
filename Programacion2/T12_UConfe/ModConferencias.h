#pragma once
#include "ConferenciaPresencial.h"
#include "ConferenciaVirtual.h"
#define CS 10
class ModConferencias
{
private:
	int ind = 0;
	Conferencia** conferencias;
public:
	ModConferencias();
	~ModConferencias();
	Conferencia* buscar(int numero);
	void registrarConferenciaPresencial(ConferenciaPresencial* conferenciapresencial);
	void registrarConferenciaVirtual(ConferenciaVirtual* conferenciavirtual);
	string toJsonConferenciaPresencial();
	string toJsonConferenciaVirtual();
	string toJson();
};

