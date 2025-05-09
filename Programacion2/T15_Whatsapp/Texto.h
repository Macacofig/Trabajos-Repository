#pragma once
#include "Mensaje.h"
class Texto :public Mensaje
{
private:
	string descripcion;
public:
	Texto(long numero, string descripcion);
	~Texto();
	string toJson();
};

