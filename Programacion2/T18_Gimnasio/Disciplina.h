#pragma once
#include "Grupo.h"
#include "ListaGen.h"
class Disciplina
{
private:
	string nombre;
	ListaGen<Grupo>* grupos;
public:
	Disciplina(string nombre);
	~Disciplina();
	ListaGen<Grupo>*& getGrupos();
	string toString();
};

