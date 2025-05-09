#include "ModSesiones.h"

ModSesiones::ModSesiones(int tam)
{
	ind = 0;
	this->tam = tam;
	sesiones = new Sesion * [tam];
}

ModSesiones::~ModSesiones()
{
	for (int i = 0; i < ind; i++)
	{
		delete sesiones[i];
	}
	delete[] sesiones;	
}

int ModSesiones::getind()
{
	return ind;
}

int ModSesiones::gettam()
{
	return tam;
}

void ModSesiones::registrar(Sesion* sesion)
{
	if (ind < tam)
	{
		sesiones[ind] = sesion;
		ind++;
	}
	else
	{
		cout << "Limite excedido" << endl;
	}
}

Sesion* ModSesiones::buscar(int idSesion)
{
	for (int i = 0; i < ind; i++)
	{
		if (sesiones[i]->getidSesion() == idSesion)
		{
			return sesiones[i];
		}
	}
	return NULL;
}

void ModSesiones::mostrar()
{
	cout << "Sesiones:" << endl;
	cout << toJson();
}

string ModSesiones::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << sesiones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}

	}
	ss << "]";
	return ss.str();
}
