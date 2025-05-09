#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Vehiculo
{
protected: //visible para las clases hijas pero no para las demas
	string patente;
	string marca;
	int modelo;
	int km;
public:
	Vehiculo(string patente,string marca,int modelo,int km);
	~Vehiculo();
	string getPatente();

	virtual string toJson(); //virutal= el metodo puede estar sobreescrito en la clase hija
	void mostrar();

};

