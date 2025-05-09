#include "Bloque.h"

Bloque::Bloque(int id, int x, int y)
	:Objeto(id,x,y,"bloque")
{
}

Bloque::~Bloque()
{
}

string Bloque::toString()
{
	stringstream ss;
	ss << "{|}";
	return ss.str();
}
