#pragma once
#include "Matriz.h"
#include "Cliente.h"
#include "SingleClientes.h"
class Funcion
{
private:
	Matriz<Cliente*> sala;
	int id;
	string nombre;
public:
	Funcion(int id, string nombre, int filas, int columnas);
	Funcion(int id);
	~Funcion();
	int getid();
	string toString();
	static	string toStatic(Funcion* f);
	bool operator==(Funcion* f);
	void registrarEnSala(Cliente* c, int fil, int col);
};

