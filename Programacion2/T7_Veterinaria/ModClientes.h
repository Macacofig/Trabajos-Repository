#pragma once
#include "Cliente.h"
class ModClientes
{
private:
	int ind;
	int tam;
	Cliente** clientes;
public:
	ModClientes(int tam);
	~ModClientes();
	void registar(Cliente* cliente);
	Cliente* buscar(int ci);
	string toString();
	void ordenar();
};

