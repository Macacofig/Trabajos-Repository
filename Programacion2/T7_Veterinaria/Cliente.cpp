#include "Cliente.h"

Cliente::Cliente(int ci, string nombre, int fono)
	:mascotas(C_M_MAS)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;
}

Cliente::~Cliente()
{
}

int Cliente::getCi()
{
	return ci;
}

ModMascotas& Cliente::getMascotas()
{
	return mascotas;
}

string Cliente::toString()
{
	stringstream ss;
	ss << "{\"ci\":"<<ci<<",\"nombre\":\""<<nombre<<"\",\"fono\":"<<fono<<",\"mascotas\":"<<mascotas.toString()<<"}";
	return ss.str();
}

string Cliente::toString_3()
{
	stringstream ss;
	ss << "{\"ci\":" << ci << ",\"nombre\":\"" << nombre << "\",\"fono\":" << fono<<"}";
	return ss.str();
}