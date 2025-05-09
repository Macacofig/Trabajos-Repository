#pragma once
#include "Accion.h"
class SMS :public Accion
{
public:
	SMS(int id, long fecha);
	~SMS();
	string toJson();
};

