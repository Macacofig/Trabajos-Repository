#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Mensaje
{
protected:
	long numero;
	string tipo;
public:
	Mensaje(long numero,string tipo);
	long getNumero();
	~Mensaje();
	virtual string toJson()=0;
	static string toJsonStatic(Mensaje* m);
};

