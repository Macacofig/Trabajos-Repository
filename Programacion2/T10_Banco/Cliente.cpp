#include "Cliente.h"

Cliente::Cliente(int ci, string nom)
{
	this->ci = ci;
	this->nom = nom;
}

Cliente::~Cliente()
{
}

int Cliente::getCi()
{
	return ci;
}

void Cliente::setCi(int ci)
{
	this->ci = ci;
}

void Cliente::setNom(string nom)
{
	this->nom = nom;
}

ModCuentas& Cliente::getCuentas()
{
	return cuentas;
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Ci\":" << ci << ",";
	ss << "\"Nombre\":\"" << nom << "\",";
	ss << "\"Cuentas\":" << cuentas.toJson();
	ss << "}";
	return ss.str();
}
