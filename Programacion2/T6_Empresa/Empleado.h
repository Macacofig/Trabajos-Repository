#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Empleado
{
private:
	int Ci;
	string Nombre;
	string AreaEspe;
	int Aniostrabajo;
public:
	Empleado();
	Empleado(int Ci, string Nombre, string AreaEspe, int Aniostrabajo);
	~Empleado();
	int getCi();
	string getNombre();
	string getAreaEspe();
	int getAniostrabajo();
	void setCi(int Ci);
	void setNombre(string Nombre);
	void setAreaEspe(string AreaEspe);
	void setAniostrabajo(int Aniostrabajo);
	void mostrar();
	string toJson();
};

