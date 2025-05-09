#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Avion
{
private:
	int placa;
	int filas;
	int columnas;
public:
	Avion(int placa, int filas, int columnas);
	~Avion();
	int getPlaca();
	int getFilas();
	int getColumnas();
	string toJson();
};

