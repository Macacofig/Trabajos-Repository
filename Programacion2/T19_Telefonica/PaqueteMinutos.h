#pragma once
#include "Paquete.h"
class PaqueteMinutos :public Paquete
{
public:
	PaqueteMinutos(int saldo);
	~PaqueteMinutos();
	string toJson();
};

