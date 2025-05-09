#pragma once
#include "Conferencia.h"
class ConferenciaPresencial :public Conferencia
{
private:
	string lugar;
public:
	ConferenciaPresencial(int numero, long fecha, string lugar);
	~ConferenciaPresencial();
	string toJson();
};

