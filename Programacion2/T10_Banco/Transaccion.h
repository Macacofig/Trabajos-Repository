#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Transaccion
{
private:
	int id;
	string Fecha;
	string Hora;
	int monto;
	string tipo;
public:
	Transaccion(int id, string Fecha, string Hora, int monto, string tipo);
	~Transaccion();
	int getMonto();
	int getId();
	string toJson();
};

