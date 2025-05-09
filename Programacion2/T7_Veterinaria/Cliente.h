#pragma once
#include "ModMascotas.h"
#define C_M_MAS 10
class Cliente
{
private:
	int ci;
	string nombre;
	int fono;
	ModMascotas mascotas;
public:
	Cliente(int ci, string nombre, int fono);
	~Cliente();
	int getCi();
	ModMascotas& getMascotas();
	string toString();
	string toString_3();
};

