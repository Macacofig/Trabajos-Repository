#include "ModAtenciones.h"

ModAtenciones::ModAtenciones(int tam)
{
	ind = 0;
	this->tam = tam;
	atenciones = new Atencion * [tam];
}

ModAtenciones::~ModAtenciones()
{
	delete[]atenciones;
}

void ModAtenciones::registar(Atencion* atencion)
{
	if (ind < tam)
	{
		atenciones[ind] = atencion;
		ind++;
	}
	else
	{
		cout << "Limite excedido";
	}
}

Atencion* ModAtenciones::buscar(int codigo)
{
	for (int i = 0; i < ind; i++)
	{
		if (atenciones[i]->getCodigo() == codigo)
		{
			return atenciones[i];
		}
	}
	return NULL;
}

string ModAtenciones::toString()
{
	ordenar();
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << atenciones[i]->toString();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

void ModAtenciones::ordenar()
{
	Atencion* aux;
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind - 1; j++)
		{
			if (atenciones[j]->getCodigo() > atenciones[j + 1]->getCodigo())
			{
				aux = atenciones[j];
				atenciones[j] = atenciones[j + 1];
				atenciones[j + 1] = aux;
			}
		}
	}
}
