#pragma once
#include "Cliente.h"
class Menor :public Cliente
{
public:
	Menor(int ci, string nombre);
	~Menor();
	string toString();
};

