#pragma once
#include "ModTransacciones.h"

class Cuenta
{
protected:
	int id;
	int saldo;
	ModTransacciones transacciones;
public:
	Cuenta(int id,int saldo);
	~Cuenta();
	int getId();
	int getSaldo();
	virtual void actualizacion(string Fecha, string Hora, string tipo) = 0; //metodo abstrado, no en cpp, y se coloca 0
	ModTransacciones& getTransacciones();
	virtual string toJson();
};
/*
Clases abstractas: No pueden ser Instanciadas, no se crean objetos de dicha clase
basta que una clase tenga un metodo abstracto se convierte en una clase abstracta
(No se conoce la implemntacion de dicha clase)
Clases concretas: Se creara objetos de dichas clases
*/
