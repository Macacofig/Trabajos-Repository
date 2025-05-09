#pragma once
#include "Cliente.h"
class Adulto :public Cliente
{
public:
	Adulto(int ci, string nombre);
	~Adulto();
	string toString();
};

