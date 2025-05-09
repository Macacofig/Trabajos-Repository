#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Paquete
{
protected:
	string tipo;
public:
	Paquete(string tipo);
	~Paquete();
	string getTipo();
	virtual string toJson() = 0;
};

