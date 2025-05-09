#include "EGCompuesto.h"

EGCompuesto::EGCompuesto(int id)
	:ElementoGrafico(id)
{
	ind = 0;
	elementos = new ElementoGrafico * [ELE];
}

EGCompuesto::~EGCompuesto()
{
	delete[] elementos;
}

void EGCompuesto::dibujar()
{
	for (int i = 0; i < ind; i++)
	{
		elementos[i]->dibujar();
	}
}

void EGCompuesto::borrar()
{
	for (int i = 0; i < ind; i++)
	{
		elementos[i]->borrar();
	}
}

void EGCompuesto::agregar(ElementoGrafico* elemento)
{
	if (ind < ELE)
	{
		elementos[ind] = elemento;
		ind++;
	}
}
