#pragma once
#include "CuentaDepositoRetiro.h"
class Ahorro :public CuentaDepositoRetiro
{
private:
	int MantMensual;
public:
	Ahorro(int id, int saldo);
	~Ahorro();
	void actualizacion(string Fecha, string Hora);
	string toJson();
};

