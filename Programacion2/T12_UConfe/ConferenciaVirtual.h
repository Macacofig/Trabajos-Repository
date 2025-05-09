#pragma once
#include "Conferencia.h"
class ConferenciaVirtual :public Conferencia
{
private:
	string link;
public:
	ConferenciaVirtual(int numero, long fecha, string link);
	~ConferenciaVirtual();
	string toJson();
};

