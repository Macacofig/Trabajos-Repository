#include "Villano.h"

Villano::Villano(int id, int x, int y)
	:Personaje(id, x, y)
{
}

Villano::~Villano()
{
}

string Villano::toString()
{
	stringstream ss;
	ss << "{V:" << Objeto::toString() << "}";
	return ss.str();
}
