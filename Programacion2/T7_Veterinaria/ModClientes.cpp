#include "ModClientes.h"

ModClientes::ModClientes(int tam)
{
	ind = 0;
	this->tam = tam;
	clientes = new Cliente * [tam];
}

ModClientes::~ModClientes()
{
	for (int i = 0; i < ind; i++)
	{
		delete clientes[i];
	}
	delete[] clientes;
}

void ModClientes::registar(Cliente* cliente)
{
	if (ind < tam)
	{
		clientes[ind] = cliente;
		ind++;
	}
	else
	{
		cout << "Limite excedido";
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

string ModClientes::toString()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << clientes[i]->toString();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

void ModClientes::ordenar()
{
	Cliente* aux;
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind-1; j++)
		{
			if (clientes[j]->getCi() < clientes[j + 1]->getCi())
			{
				aux = clientes[j];
				clientes[j] = clientes[j + 1];
				clientes[j + 1] = aux;
			}
		}
	}
}
