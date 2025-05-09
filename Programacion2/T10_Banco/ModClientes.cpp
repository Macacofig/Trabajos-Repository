#include "ModClientes.h"

ModClientes::ModClientes()
{
	ind = 0;
	clientes = new Cliente * [CLS];
}

ModClientes::~ModClientes()
{
	delete[] clientes;
}

void ModClientes::registrar(Cliente* cliente)
{
	if (ind < CLS)
	{
		clientes[ind] = cliente;
		ind++;
	}
}

Cliente* ModClientes::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (clientes[i]->getCi() == ci)
		{
			return clientes[i];
		}
	}
	return NULL;
}

void ModClientes::eliminar(int ci)
{
	int j;
	for (int i = 0; i < ind; i++)
	{
		if (clientes[i]->getCi() == ci)
		{
			clientes[i] = NULL;
			for (j = i + 1; j < ind; j++)
			{
				clientes[j - 1] = clientes[j];
			}
			clientes[j - 1] = NULL;
			ind--;
		}
	}
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
