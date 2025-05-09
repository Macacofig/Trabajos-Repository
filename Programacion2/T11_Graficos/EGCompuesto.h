#pragma once
#include "ElementoGrafico.h"
#define ELE 10
class EGCompuesto :public ElementoGrafico
{
private:
	ElementoGrafico** elementos;
	int ind;
public:
	EGCompuesto(int id);
	~EGCompuesto();
	void dibujar();
	void borrar();
	void agregar(ElementoGrafico* elemento);
};

