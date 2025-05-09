#pragma once

#include"Objeto.h"

class Personaje
	:public Objeto
{

public:
	Personaje(int id, int x, int y);
	~Personaje();

	string toString();
};

