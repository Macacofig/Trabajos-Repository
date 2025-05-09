#include "Vehiculo.h"

Vehiculo::Vehiculo(string patente, string marca, int modelo, int km)
{
	this->patente = patente;
	this->marca = marca;
	this->modelo = modelo;
	this->km = km;
}

Vehiculo::~Vehiculo()
{
}

string Vehiculo::getPatente()
{
	return patente;
}

string Vehiculo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Patente\":\"" << patente << "\",";
	ss << "\"Marca\":\"" << marca << "\",";
	ss << "\"Modelo\":" << modelo << ",";
	ss << "\"Km\":" << km ;
	ss << "}";
	return ss.str();
}

void Vehiculo::mostrar()
{
	cout << "Vehiculo:" << endl;
	cout << toJson();
}
