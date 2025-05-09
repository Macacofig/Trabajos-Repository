#include "ModEquiposInscritos.h"

ModEquiposInscritos::ModEquiposInscritos(int tam)
{
	ind = 0;
	this->tam = tam;
	equiposinscritos = new EquipoInscrito*[tam];
}

ModEquiposInscritos::~ModEquiposInscritos()
{
	for (int i = 0; i < ind; i++)
	{
		delete equiposinscritos[i];
	}
	delete [] equiposinscritos;
}

int ModEquiposInscritos::getind()
{
	return ind;
}

int ModEquiposInscritos::gettam()
{
	return tam;
}

void ModEquiposInscritos::registrar(EquipoInscrito* equipoinscrito)
{
	if (ind < tam)
	{
		equiposinscritos[ind] = equipoinscrito;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

EquipoInscrito* ModEquiposInscritos::buscar(int ideqins)
{
	for (int i = 0; i < ind; i++)
	{
		if (equiposinscritos[i]->getideqins() == ideqins)
		{
			return equiposinscritos[i];
		}
	}
	return NULL;
}

void ModEquiposInscritos::mostrar()
{
	cout << "EquiposInscritos:" << endl;
	cout << toJson() << endl;
}

string ModEquiposInscritos::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << equiposinscritos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
