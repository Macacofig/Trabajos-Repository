#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Paquete
{
protected:
	int saldo;
	string tipo;
public:
	Paquete(int saldo,string tipo);
	Paquete(string tipo);
	~Paquete();
	int getSaldo();
	string getTipo();
	void setSaldo(int saldo);
	bool operator==(Paquete* p);
	virtual string toJson();
	static string toStatic(Paquete* p);
};

