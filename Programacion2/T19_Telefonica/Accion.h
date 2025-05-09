#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Accion
{
protected:
	int id;
	int fecha;
	string tipo;
public:
	Accion(int id, int fecha, string tipo);
	~Accion();
	string getTipo();
	virtual string toJson();
	static string toStatic(Accion* a);
};

