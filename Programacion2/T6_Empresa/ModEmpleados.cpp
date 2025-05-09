#include "ModEmpleados.h"

ModEmpleados::ModEmpleados(int tam)
{
	ind = 0;
	this->tam = tam;
	empleados = new Empleado * [tam];
}

ModEmpleados::~ModEmpleados()
{
		delete[] empleados;
}

int ModEmpleados::getind()
{
	return ind;
}

int ModEmpleados::gettam()
{
	return tam;
}

void ModEmpleados::registrar(Empleado* empleado)
{
	if (ind < tam)
	{
		empleados[ind] = empleado;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Empleado* ModEmpleados::buscar(int Ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (empleados[i]->getCi() == Ci)
		{
			return empleados[i];
		}
	}
	return NULL;
}

void ModEmpleados::ordenar()
{
	Empleado* eaux;
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1; j++)
		{
			if (empleados[j]->getCi() > empleados[j + 1]->getCi())
			{
				eaux = empleados[j];
				empleados[j] = empleados[j + 1];
				empleados[j + 1] = eaux;
			}
		}
	}
}
void ModEmpleados::mostrar()
{
	cout << "Empleados:"<<endl;
	cout << toJson();
}

string ModEmpleados::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << empleados[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
