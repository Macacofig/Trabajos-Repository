#pragma once
#include "EGBasico.h"
#include "Formato.h"
class Linea :public EGBasico
{
private:
	int orientacion;
	int tamano;
public:
	Linea(int id, int x, int y,int orientacion,int tamano);
	~Linea();
	int getOri();
	int gerTam();
	void setOri(int orientacion);
	void dibujarhorizontal();
	void dibujarvertical();
	void borrarHorizontal();
	void borrarVertical();
	void dibujar();
	void borrar();
};

