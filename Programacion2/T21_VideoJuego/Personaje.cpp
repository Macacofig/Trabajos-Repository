#include "Personaje.h"

Personaje::Personaje(int id, int x, int y)
	:Objeto(id,x,y,"Personaje")
{
}

Personaje::~Personaje()
{
}

string Personaje::toString()
{
	stringstream ss;
	return ss.str();
}
