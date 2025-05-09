#pragma once
#include "Paquete.h"
class PaqueteMegas :public Paquete
{
public:
	PaqueteMegas(int saldo);
	~PaqueteMegas();
	string toJson();
};

