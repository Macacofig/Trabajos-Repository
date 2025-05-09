#include "ModClientes.h"

ModClientes::ModClientes()
{
	ind = 0;
	clientes = new Cliente * [CS];
}

ModClientes::~ModClientes()
{
	delete[] clientes;
}

void ModClientes::registrar(Cliente* cliente)
{
	if (ind < PS)
	{
		clientes[ind] = cliente;
		ind++;
	}
}

Cliente* ModClientes::buscar(string nombre)
{
	for (int i = 0; i < ind; i++)
	{
		if (clientes[i]->getNombre() == nombre)
		{
			return clientes[i];
		}
	}
	return NULL;
}

string ModClientes::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << clientes[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
