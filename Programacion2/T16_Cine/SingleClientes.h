#pragma once
#include "Cliente.h"
#include "ListaGen.h"
class SingleClientes
{
private:
	ListaGen<Cliente>* clientes;
	SingleClientes();
public:
	
	~SingleClientes();
	static SingleClientes getInst();
	ListaGen<Cliente>* getClientes();
};

