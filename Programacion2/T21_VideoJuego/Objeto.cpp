#include "Objeto.h"

Objeto::Objeto(int id, int x, int y, string tipo)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->tipo = tipo;
}

Objeto::Objeto(int id)
{
	this->id = id;
}

Objeto::~Objeto()
{
}

int Objeto::getId()
{
	return id;
}

int Objeto::getX()
{
	return x;
}

int Objeto::getY()
{
	return y;
}

string Objeto::getTipo()
{
	return tipo;
}

void Objeto::setX(int x)
{
	this->x = x;
}

void Objeto::setY(int y)
{
	this->y = y;
}

string Objeto::toString()
{
	stringstream ss;
	ss << "{id:"<<id<<",x:" << x << ",y:" << y << "}";
	return ss.str();
}

string Objeto::toStatic(Objeto* o)
{
	return o->toString();
}

bool Objeto::operator==(Objeto* o)
{
	return id==o->getId();
}
