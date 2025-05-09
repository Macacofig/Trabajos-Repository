#include "Vuelo.h"

Vuelo::Vuelo(int numero, Avion* avion) 
	:asientos(avion->getFilas()*avion->getColumnas())
{
	this->numero = numero;
	this->avion = avion;
	agregarAsientos();
}

Vuelo::~Vuelo()
{
}

int Vuelo::getNumero()
{
	return numero;
}

string Vuelo::toJson()
{
	stringstream ss;
	ss << "{\"numero\":"<<numero
		<<",\"avion\":"<<avion->toJson()
		<<",\"asientos\":"<<asientos.toJson()<<"}";
	return ss.str();
}

void Vuelo::registrarPasajero(int fila, int columna, Persona* p)
{
	Asiento* a = asientos.buscar(fila, columna);
	if (a != NULL)
	{
		a->setPasajero(p);
	}
}

void Vuelo::intercambiarAsiento(Asiento* a1, Asiento* a2)
{
	Asiento* ap1 = asientos.buscar(a1->getFila(), a1->getColumna());
	Asiento* ap2 = asientos.buscar(a2->getFila(), a2->getColumna());
	if (ap1 != NULL && ap2 != NULL)
	{
		Persona* aux=ap1->getPasajero();
		ap1->setPasajero(ap2->getPasajero());
		ap2->setPasajero(aux);
	}
}

void Vuelo::agregarAsientos()
{
	for (int i=0;i<avion->getFilas();i++)
	{
		for (int j=0;j<avion->getColumnas();j++)
		{
			asientos.registarAsiento(new Asiento(i + 1, j + 1));
		}
	}
}
