#include "Heroe.h"

Heroe::Heroe(int id, int x, int y)
	:Personaje(id,x,y)
{
}

Heroe::~Heroe()
{
}

string Heroe::toString()
{
	stringstream ss;
	ss << "{H:" << Objeto::toString() << "}";
	return ss.str();
}
