#pragma once
#include "Paquete.h"
class PaqueteMinutos :public Paquete
{
private:
	int minutos;
public:
	PaqueteMinutos(int minutos);
	~PaqueteMinutos();
	int getMinutos();
	void setMinutos(int minutos);
	string toJson();
};

