#include "SalaCine.h"

SalaCine::SalaCine(string nombre, int filas, int columnas)
{
	this->nombre = nombre;
	this->filas = filas;
	this->columnas = columnas;
}

SalaCine::~SalaCine()
{
}

void SalaCine::registrar(Cliente* c)
{
	SingleClientes::getInst().getClientes()->registrar(c);
}

void SalaCine::registrarCliente(int id, int fila, int col, int ci)
{
	Funcion* f = funciones.buscar(new Funcion(id));
	if (f != NULL)
	{
		f->registrarEnSala(new Cliente(ci), fila, col);
	}
}

void SalaCine::crearFuncion(int ind, string nombre)
{
	funciones.registrar(new Funcion(ind, nombre, filas, columnas));
}

string SalaCine::toString()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre 
		<< "\",\"funciones\":" << funciones.toString(Funcion::toStatic) << "}";
	return ss.str();
}
