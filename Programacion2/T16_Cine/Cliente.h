#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Cliente
{
protected:
	int ci;
	string nombre;
	string tipo;
public:
	Cliente(int ci, string nombre,string tipo);
	Cliente(int ci);
	~Cliente();
	int getCi();
	virtual string toString();
	static string toStatic(Cliente* c);
	bool operator==(Cliente* c);
};

