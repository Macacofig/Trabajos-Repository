#include "Linea.h"

Linea::Linea(int id, int x, int y, int orientacion, int tamano)
	:EGBasico(id,"Linea", x, y)
{
	this->orientacion = orientacion;
	this->tamano = tamano;
}

Linea::~Linea()
{
}

int Linea::getOri()
{
	return orientacion;
}

int Linea::gerTam()
{
	return tamano;
}

void Linea::setOri(int orientacion)
{
	this->orientacion = orientacion;
}

void Linea::dibujarhorizontal()
{
	for (int i = 0; i < tamano; i++)
	{
		gotoxy(x + i, y);
		cout << "*";
	}
}

void Linea::dibujarvertical()
{
	for (int i = 0; i < tamano; i++)
	{
		gotoxy(x, y + i);
		cout << "*";
	}
}

void Linea::borrarHorizontal()
{
	for (int i = 0; i < tamano; i++)
	{
		gotoxy(x + i, y);
		cout << " ";
	}
}

void Linea::borrarVertical()
{
	for (int i = 0; i < tamano; i++)
	{
		gotoxy(x, y + i);
		cout << " ";
	}
}

void Linea::dibujar()
{
	if (orientacion == 0) //horizontal
	{
		dibujarhorizontal();
	}
	if (orientacion == 1) //vertical
	{
		dibujarvertical();
	}
}

void Linea::borrar()
{
	if (orientacion == 0) //horizontal
	{
		borrarHorizontal();
	}
	if (orientacion == 1) //vertical
	{
		borrarVertical();
	}
}
