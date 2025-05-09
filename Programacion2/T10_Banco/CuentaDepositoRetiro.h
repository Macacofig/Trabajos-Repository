#pragma once
#include "Cuenta.h"
class CuentaDepositoRetiro :public Cuenta
{
public:
	CuentaDepositoRetiro(int id, int saldo);
	~CuentaDepositoRetiro();
	virtual void Deposito(string fecha,string hora,int cantDep);
	virtual void Retiro(string fecha,string hora, int cantDep);
};

