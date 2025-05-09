#pragma once
#include "Mascota.h"
class ModMascotas
{
private:
	int ind;
	int tam;
	Mascota** mascotas;
public:
	ModMascotas(int tam);
	~ModMascotas();
	void registar(Mascota* mascota);
	Mascota* buscar(string nombre);
	string toString();
	void ordenar();
};

