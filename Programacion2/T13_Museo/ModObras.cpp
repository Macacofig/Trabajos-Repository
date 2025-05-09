#include "ModObras.h"

ModObras::ModObras()
{
	ind = 0;
	obras = new Obra * [OS];
}

ModObras::~ModObras()
{
	delete[] obras;
}

void ModObras::registrar(Obra* obra)
{
	if (ind < OS)
	{
		obras[ind] = obra;
		ind++;
	}
}

string ModObras::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << obras[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
