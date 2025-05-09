#include "Modjugadores.h"

Modjugadores::Modjugadores(int tam)
{
	this->tam = tam;
	ind = 0;
	jugadores = new Jugador * [tam];
}

Modjugadores::~Modjugadores()
{
	delete [] jugadores;
}

int Modjugadores::getind()
{
	return ind;
}

int Modjugadores::gettam()
{
	return tam;
}

void Modjugadores::registrarju(Jugador* jugador)
{
	if (ind < tam)
	{
		jugadores[ind]=jugador;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Jugador* Modjugadores::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (jugadores[i]->getci() == ci)
		{
			return jugadores[i];
		}
	}
	return NULL;
}

void Modjugadores::mostrar()
{
	cout << "Jugadores:" << endl;
	cout << toJson() << endl;
}

string Modjugadores::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << jugadores[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
