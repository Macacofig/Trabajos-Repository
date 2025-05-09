#pragma once
#include "Cliente.h"
#define CS 10
class ModClientes
{
private:
	int ind;
	Cliente** clientes;
public:
	ModClientes();
	~ModClientes();
	void registrar(Cliente* cliente);
	Cliente* buscar(string nombre);
	string toJson();
};

