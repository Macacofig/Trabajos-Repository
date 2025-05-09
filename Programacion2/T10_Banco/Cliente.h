#pragma once
#include "ModCuentas.h"

class Cliente
{
private:
	int ci;
	string nom;
	ModCuentas cuentas;
	
public:
	Cliente(int ci, string nom);
	~Cliente();
	int getCi();
	void setCi(int ci);
	void setNom(string nom);
	ModCuentas& getCuentas();
	
	string toJson();
};

