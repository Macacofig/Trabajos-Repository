#include "SingleClientes.h"

SingleClientes::SingleClientes()
{
	clientes = new ListaGen<Cliente>;
}

SingleClientes::~SingleClientes()
{
}

SingleClientes SingleClientes::getInst()
{
	static SingleClientes ins;
	return ins;
}

ListaGen<Cliente>* SingleClientes::getClientes()
{
	return clientes;
}
