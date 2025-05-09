#pragma once
#include "Cliente.h"
#include "ListaGen.h"
class SingletonClientes
{
private:
	ListaGen<Cliente> clientes;
public:
	static SingletonClientes& getInst();
	~SingletonClientes();
	ListaGen<Cliente>& getClientes();
	void registrar(Cliente* cliente);
	Cliente* buscar(int ci);
	string toString();
private:
	SingletonClientes();
};

