#pragma once
#include "Atencion.h"
class AtencionPeluqueria :public Atencion
{
private:
	int DurMinutos;
public:
	AtencionPeluqueria(int codigo);
	AtencionPeluqueria(int codigo, string descripcion, int costo, int Durminutos);
	~AtencionPeluqueria();
	string toJson();
};

