#pragma once
#include "Cuenta.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CuentaDepositoPF :public Cuenta
{
private:
	string FechaIn;
	string FechaFin;
	int IntAnual;
public:
	CuentaDepositoPF(int id, int saldo,string FechaIn, string FechaFin);
	~CuentaDepositoPF();
	void ActualizacionCDPF(string Fecha, string Hora);
	string toJson();
};

