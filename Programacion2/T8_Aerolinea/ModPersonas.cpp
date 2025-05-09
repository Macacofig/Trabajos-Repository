#include "ModPersonas.h"

ModPersonas::ModPersonas(int tam)
{
	ind = 0;
	this->tam = tam;
	personas = new Persona * [tam];
}

ModPersonas::~ModPersonas()
{
	delete[] personas;
}

void ModPersonas::registrar(Persona* persona)
{
	if (ind < tam)
	{
		personas[ind] = persona;
		ind++;
	}
	else
		cout << "Limite excedido" << endl;
}

Persona* ModPersonas::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (personas[i]->getCi() == ci)
		{
			return personas[i];
		}
	}
	return NULL;
}

string ModPersonas::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << personas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
