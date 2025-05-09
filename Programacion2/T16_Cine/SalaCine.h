#pragma once
#include "ListaGen.h"
#include "Funcion.h"
#include "SingleClientes.h"
class SalaCine
{
private:
	string nombre;
	int filas;
	int columnas;
	ListaGen<Funcion> funciones;
public:
	SalaCine(string nombre, int filas, int columnas);
	~SalaCine();
	static void registrar(Cliente* c);
	void registrarCliente(int id, int fila, int col, int ci);
	void crearFuncion(int ind, string nombre);
	string toString();
};

