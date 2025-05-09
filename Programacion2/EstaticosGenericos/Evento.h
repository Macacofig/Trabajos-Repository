#pragma once
#include "GeneradorIds.h"
class Evento
{
private:
	int id;
	int minuto;
	string tipo;
public:
	Evento(int minuto, string tipo);
	~Evento();
	string toJson();
	static string toJson(Evento* e);
};

