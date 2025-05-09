#include "Modequipos.h"

Modequipos::Modequipos(int tam)
{
	ind = 0;
	this->tam = tam;
	equipos = new Equipo * [tam];
}

Modequipos::~Modequipos()
{
	for (int i = 0; i < ind; i++)
	{
		delete equipos[i];
	}
	delete[] equipos;
}

int Modequipos::getind()
{
	return ind;
}

int Modequipos::gettam()
{
	return tam;
}

void Modequipos::registrareq(Equipo* equipo)
{
	if (ind < tam)
	{
		equipos[ind] = equipo;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Equipo* Modequipos::buscar(int codequipo)
{
	for (int i = 0; i < ind; i++)
	{
		if (equipos[i]->getcodequipo() == codequipo)
		{
			return equipos[i];
		}
	}
	return NULL;
}

void Modequipos::mostrar()
{
	cout << "Equipos:" << endl;
	cout << toJson() << endl;
}

string Modequipos::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << equipos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
