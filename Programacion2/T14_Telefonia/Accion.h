#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Accion
{
protected:
	string tipo;
	int id;
	long fecha;
public:
	Accion(string tipo, int id, long fecha);
	~Accion();
	virtual string toJson() = 0;
};

