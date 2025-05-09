#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Obra
{
protected:
	string titulo;
	int precio;
public:
	Obra(string titulo, int precio);
	~Obra();
	virtual string toJson()=0;
};

