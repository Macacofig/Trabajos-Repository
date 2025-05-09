#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Equipo
{
private:
	int codequipo;
	string nombrequipo;
public:
	Equipo(int codequipo,string nombrequipo);
	~Equipo();
	int getcodequipo();
	string getnombrequipo();
	void mostrar();
	string toJson();
};

