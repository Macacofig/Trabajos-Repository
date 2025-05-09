#include "SingletonSocios.h"

SingletonSocios::SingletonSocios()
{
	socios = new ListaGen<Socio>;
}

SingletonSocios::~SingletonSocios()
{
}

SingletonSocios& SingletonSocios::getInst()
{
	static SingletonSocios ins;
	return ins;
}

ListaGen<Socio>*& SingletonSocios::getSocios()
{
	return socios;
}

string SingletonSocios::toString()
{
	stringstream ss;
	socios->ordenar(Socio::OrAC);
	ss << "{\"socios\":" << socios->toJson(Socio::toStatic) << "}";
	return ss.str();
}
