#include "Corriente.h"

Corriente::Corriente(int id, int saldo)
	:CuentaDepositoRetiro( id, saldo)
{
	IntAnual = 3 / 100;
}

Corriente::~Corriente()
{
}

void Corriente::actualizacion(string Fecha, string Hora)
{
	saldo=saldo + (saldo * IntAnual);
	int id = transacciones.getInd() + 1;
	transacciones.registrar(new Transaccion(id, Fecha, Hora, IntAnual, "Actualizacion Cuenta Corriente"));
}

string Corriente::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Id\":" << id << ",";
	ss << "\"Interes Mensual\":" << IntAnual << ",";
	ss << "\"Saldo\":" << saldo << ",";
	ss << "\"Transacciones\":" << transacciones.toJson();
	ss << "}";
	return ss.str();
}
