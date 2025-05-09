#pragma once
#include "Mascota.h"
#include "ListaGen.h"

class Cliente
{
private:
	int ci;
	string nombre;
	int fono;
	ListaGen<Mascota> mascotas;
public:
	Cliente(int ci);
	Cliente(int ci, string nombre, int fono);
	~Cliente();
	bool operator==(Cliente* c1);
	static bool cmpCIMm(Cliente* c1, Cliente* c2);
	ListaGen<Mascota>& getMascotas();
	int getCi();
	static string toStatic(Cliente* c);
	string toJson();
	string toJsonB();
};

