#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Socio
{
private:
	int ci;
	string nombre;
public:
	Socio(int ci, string nombre);
	Socio(int ci);
	~Socio();
	int getCi();
	string getNombre();
	string toJson();
	bool operator==(Socio* s);
	static bool OrAC(Socio* s1, Socio* s2);
	static string toStatic(Socio* s);

};

