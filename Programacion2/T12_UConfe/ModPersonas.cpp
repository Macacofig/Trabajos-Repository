#include "ModPersonas.h"

ModPersonas::ModPersonas()
{
	ind = 0;
	personas = new Persona* [PS];
}

ModPersonas::~ModPersonas()
{
	delete[] personas;
}

void ModPersonas::registrar(Persona* persona)
{
	if (ind < PS)
	{
		personas[ind] = persona;
		ind++;
	}
}

Persona* ModPersonas::buscar(string nombre)
{
	for (int i = 0; i < ind; i++)
	{
		if (personas[i]->getNombre() == nombre)
		{
			return personas[i];
		}
	}
	return NULL;
}

Persona* ModPersonas::operator[](int pos)
{
	return personas[pos];
}

void ModPersonas::operator<<(Persona* persona)
{
	registrar(persona);
}

void ModPersonas::ordenar()
{
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1; j++)
		{
			if ((*personas[j]) > (*personas[j+1]))
			{
				Persona* tmp = personas[j];
				personas[j] = personas[j + 1];
				personas[j + 1] = tmp;
			}
		}
	}
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
