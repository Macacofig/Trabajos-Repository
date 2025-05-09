#include "Modcampeonatos.h"

Modcampeonatos::Modcampeonatos(int tam)
{
	ind = 0;
	this->tam = tam;
	campeonatos = new Campeonato * [tam];
}

Modcampeonatos::~Modcampeonatos()
{
	for (int i = 0; i < ind; i++)
	{
		delete campeonatos[i];
	}
	delete[] campeonatos;
}

int Modcampeonatos::getind()
{
	return ind;
}

int Modcampeonatos::gettam()
{
	return tam;
}

void Modcampeonatos::registrar(Campeonato* campeonato)
{
	if (ind < tam)
	{
		campeonatos[ind] = campeonato;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Campeonato* Modcampeonatos::buscar(int codcampeonato)
{
	for (int i = 0; i < ind; i++)
	{
		if (campeonatos[i]->getcodcampeonato() == codcampeonato)
		{
			return campeonatos[i];
		}
	}
	return NULL;
}

void Modcampeonatos::mostrar()
{
	cout << "Campeonatos:" << endl;
	cout << toJson() << endl;
}

string Modcampeonatos::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << campeonatos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
