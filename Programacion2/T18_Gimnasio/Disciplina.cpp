#include "Disciplina.h"

Disciplina::Disciplina(string nombre)
{
	this->nombre = nombre;
	grupos = new ListaGen<Grupo>;
}

Disciplina::~Disciplina()
{
}

ListaGen<Grupo>*& Disciplina::getGrupos()
{
	return grupos;
}

string Disciplina::toString()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"grupos\":" << grupos->toJson(Grupo::toStatic) << "}";
	return ss.str();
}
