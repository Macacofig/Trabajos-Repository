#include "ModVehiculos.h"

ModVehiculos::ModVehiculos()
{
	ind = 0;
	vehiculos = new Vehiculo * [VEH];
}

ModVehiculos::~ModVehiculos()
{
	delete[] vehiculos;
}

void ModVehiculos::ordenar()
{
	string p1;
	string p2;
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1; j++)
		{
			p1 = vehiculos[j]->getPatente();
			p2 = vehiculos[j+1]->getPatente();
			if (p1[0] > p2[0])
			{
				Vehiculo* aux;
				aux = vehiculos[j];
				vehiculos[j] = vehiculos[j + 1];
				vehiculos[j + 1] = aux;
			}
		}
	}
}

void ModVehiculos::registrar(Vehiculo* vehiculo)
{
	if (ind < VEH)
	{
		vehiculos[ind] = vehiculo;
		ind++;
	}
	else
	{
		cout << "Limite!!" << endl;
	}
}

Vehiculo* ModVehiculos::buscar(string patente)
{
	for (int i = 0; i < ind; i++)
	{
		if (vehiculos[i]->getPatente() == patente)
		{
			return vehiculos[i];
		}
	}
	return NULL;
}

void ModVehiculos::mostrar()
{
	cout << "Vehiculos" << endl;
	cout << toJson();
}

string ModVehiculos::toJson()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << vehiculos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
