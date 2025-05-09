#include "Modpartidos.h"

Modpartidos::Modpartidos(int tam)
{
	ind = 0;
	this->tam = tam;
	partidos = new Partido * [tam];
}

Modpartidos::~Modpartidos()
{
	for (int i = 0; i < ind; i++)
	{
		delete partidos[i];
	}
	delete[] partidos;
}

int Modpartidos::getind()
{
	return ind;
}

int Modpartidos::gettam()
{
	return tam;
}

void Modpartidos::registrar(Partido* partido)
{
	if (ind < tam)
	{
		partidos[ind] = partido;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Partido* Modpartidos::buscar(int numpartido)
{
	for (int i = 0; i < ind; i++)
	{
		if (partidos[i]->getnumpartido() == numpartido)
		{
			return partidos[i];
		}
	}
	return NULL;
}

void Modpartidos::mostrar()
{
	cout << "Partidos:" << endl;
	cout << toJson() << endl;
}

string Modpartidos::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << partidos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
