#pragma once
#include "ModAcciones.h"
#include "ModPaquetes.h"
#include "PaqueteMinutos.h"
#include "PaqueteSMS.h"
#include "Llamada.h"
#include "SMS.h"
class Cliente
{
private:
	string nombre;
	double saldo;
	ModAcciones acciones;
	ModPaquetes paquetes;
public:
	Cliente(string nombre, double saldo);
	~Cliente();
	double getSaldo();
	void setSaldo(double saldo);
	ModAcciones& getAcciones();
	ModPaquetes& getPaquetes();
	string getNombre();
	void ejecutarAccion(Llamada* llamada);
	void ejecutarAccion(SMS* sms);
	string toJson();
};

