#include "CuentaDepositoRetiro.h"

CuentaDepositoRetiro::CuentaDepositoRetiro(int id, int saldo)
	:Cuenta( id,  saldo)
{
}

CuentaDepositoRetiro::~CuentaDepositoRetiro()
{
}

void CuentaDepositoRetiro::Deposito(string fecha,string hora, int cantDep)
{
	saldo = saldo + cantDep;
	int id = transacciones.getInd() + 1;
	transacciones.registrar(new Transaccion(id, fecha, hora, cantDep, "Deposito"));
}

void CuentaDepositoRetiro::Retiro(string fecha,string hora, int cantRet)
{
	if (saldo >= cantRet)
	{
		saldo = saldo - cantRet;
		int id = transacciones.getInd() + 1;
		transacciones.registrar(new Transaccion(id, fecha, hora, cantRet, "Retiro"));
	}
	else
	{
		cout << "No hay suficiente saldo"<<endl;
	}
}
