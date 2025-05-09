#pragma once
#include "Obra.h"
#define OS 10
class ModObras
{
private:
	int ind;
	Obra** obras;
public:
	ModObras();
	~ModObras();
	void registrar(Obra* obra);
	string toJson();
};

