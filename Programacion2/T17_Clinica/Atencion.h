#pragma once
#include "iostream"
#include "string"
#include "sstream"
using namespace std;
class Atencion
{
protected:
	int codigo;
	string descripcion;
	int costo;
public:
	Atencion(int codigo);
	Atencion(int codigo, string descripcion, int costo);
	~Atencion();
	int getCodigo();
	bool operator==(Atencion* a);
	static bool CMPmM(Atencion* a1, Atencion* a2);
	virtual string toJson();
	static string toStatic(Atencion* at);
};

