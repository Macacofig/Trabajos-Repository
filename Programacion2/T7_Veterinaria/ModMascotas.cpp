#include "ModMascotas.h"

ModMascotas::ModMascotas(int tam)
{
	ind = 0;
	this->tam = tam;
	mascotas = new Mascota * [tam];
}

ModMascotas::~ModMascotas()
{
	delete[] mascotas;
}

void ModMascotas::registar(Mascota* mascota)
{
	if (ind < tam)
	{
		mascotas[ind] = mascota;
		ind++;
	}
	else
	{
		cout << "Limite excedido";
	}
}

Mascota* ModMascotas::buscar(string nombre)
{
	for (int i = 0; i < ind; i++)
	{
		if (mascotas[i]->getNombre() == nombre)
		{
			return mascotas[i];
		}
	}
	return NULL;
}

string ModMascotas::toString()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << mascotas[i]->toString();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

void ModMascotas::ordenar()
{
	string nom1;
	string nom2;
	Mascota* aux;
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind-1; j++)
		{
			nom1 = mascotas[j]->getNombre();
			nom2 = mascotas[j+1]->getNombre();
			if (nom1[0] > nom2[0])
			{
				aux = mascotas[j];
				mascotas[j] = mascotas[j + 1];
				mascotas[j + 1] = aux;
			}
		}
	}
}
