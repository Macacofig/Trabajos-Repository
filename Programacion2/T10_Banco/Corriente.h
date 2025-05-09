#pragma once
#include "CuentaDepositoRetiro.h"
class Corriente :public CuentaDepositoRetiro
{
private:
	int IntAnual;
public:
	Corriente(int id,int saldo);
	~Corriente();
	void actualizacion(string Fecha, string Hora);
	string toJson();
};

