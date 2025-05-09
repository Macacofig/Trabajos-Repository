#pragma once
#include "Atencion.h"
class AtencionMedica :public Atencion
{
private:
	string medicamentos;
public:
	AtencionMedica(int codigo);
	AtencionMedica(int codigo, string descripcion, int costo, string medicamentos);
	~AtencionMedica();
	string toJson();
};

