#include "Ahorro.h"

Ahorro::Ahorro(int id, int saldo)
	:CuentaDepositoRetiro(id,saldo)
{
	MantMensual = 20;
}

Ahorro::~Ahorro()
{
}

void Ahorro::actualizacion(string Fecha, string Hora)
{
	if (saldo >= MantMensual)
	{
		saldo = saldo - MantMensual;
		int id = transacciones.getInd() + 1;
		transacciones.registrar(new Transaccion(id, Fecha, Hora, MantMensual, "Actualizacion Caja Ahorro"));
	}
	else {
		cout << "Le cerraremos la cuenta" << endl;
	}
}

string Ahorro::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss << "\"Mantenimiento Mesual\":" << MantMensual << ",";
	ss << "\"Saldo\":" << saldo << ",";
	ss << "\"Transacciones\":" << transacciones.toJson();
	ss << "}";
	return ss.str();
}
