#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Mascota
{
private:
	string nombre;
	int edad;
public:
	Mascota(string nombre);
	Mascota(string nombre, int edad);
	~Mascota();
	string getNombre();
	bool operator==(Mascota* m);
	static bool CPNombre(Mascota* m1,Mascota* m2);
	string toJson();
	static string toStatic(Mascota* m);
};

