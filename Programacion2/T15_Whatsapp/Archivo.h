#pragma once
#include "Mensaje.h"
class Archivo :public Mensaje
{
private:
	string nombre;
	string ext;
public:
	Archivo(long numero, string nombre, string ext);
	~Archivo();
	string toJson();
};

