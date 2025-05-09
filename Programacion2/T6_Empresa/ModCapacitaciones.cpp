#include "ModCapacitaciones.h"

ModCapacitaciones::ModCapacitaciones(int tam)
{
	ind = 0;
	this->tam = tam;
	capacitaciones = new Capacitacion * [tam];
}

ModCapacitaciones::~ModCapacitaciones()
{
	for (int i = 0; i < ind; i++)
	{
		delete capacitaciones[i];
	}
	delete[] capacitaciones;
}

int ModCapacitaciones::getind()
{
	return ind;
}

int ModCapacitaciones::gettam()
{
	return tam;
}

void ModCapacitaciones::registrar(Capacitacion* capacitacion)
{
	if (ind < tam)
	{
		capacitaciones[ind] = capacitacion;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Capacitacion* ModCapacitaciones::buscar(int idCap)
{
	for (int i = 0; i < ind; i++)
	{
		if (capacitaciones[i]->getidCap() == idCap)
		{
			return capacitaciones[i];
		}
	}
	return NULL;
}

void ModCapacitaciones::mostrar()
{
	cout << "Capacitaciones:" << endl;
	cout << toJson();
}

string ModCapacitaciones::toJson()
{
	stringstream ss;
	ordenar();
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << capacitaciones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}

	}
	ss << "]";
	return ss.str();
}

void ModCapacitaciones::ordenar()
{
	Capacitacion* capaux; 
	string num1;
	string num2;
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1; j++)
		{
			num1 = capacitaciones[j]->getNombreArea();
			num2 = capacitaciones[j + 1]->getNombreArea();
			if (num1[0] > num2[0])
			{
				capaux = capacitaciones[j];
				capacitaciones[j] = capacitaciones[j + 1];
				capacitaciones[j + 1] = capaux;
			}
		}
	}
}
