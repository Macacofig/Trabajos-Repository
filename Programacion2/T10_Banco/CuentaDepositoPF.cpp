#include "CuentaDepositoPF.h"

CuentaDepositoPF::CuentaDepositoPF(int id, int saldo,string FechaIn, string FechaFin)
	:Cuenta(id,saldo)
{
	this->FechaFin = FechaFin;
	this->FechaIn = FechaIn;
	IntAnual = 2 / 100;
}

CuentaDepositoPF::~CuentaDepositoPF()
{
}

void CuentaDepositoPF::ActualizacionCDPF(string Fecha, string Hora)
{
	saldo=saldo + (saldo * IntAnual);
	int id = transacciones.getInd() + 1;
	transacciones.registrar(new Transaccion(id, Fecha, Hora, IntAnual, "Actualizacion Cuenta Deposito Largo Plazo"));
}

string CuentaDepositoPF::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Tipo de Cuenta: Cuenta Deposito a Plazo Fijo\"" << ",";
	ss << "\"Interes Anual\":" << IntAnual << ",";
	ss << "\"Base\":" << Cuenta::toJson();
	ss << "}";
	return ss.str();
}
