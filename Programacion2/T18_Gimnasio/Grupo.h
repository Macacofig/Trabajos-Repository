#pragma once
#include "Socio.h"
#include "ListaGen.h"
#include "SingletonSocios.h"
#include "Sesion.h"
class Grupo
{
protected:
	int cont;
	ListaGen<Socio> inscritos;
	string id;
	ListaGen<Sesion> sesiones;
public:
	Grupo(string id);
	~Grupo();
	void inscribir(int id);
	void registrarSesion(int fecha);
	void registrarAsistente(int ci, int fecha);
	virtual string toJson();
	static string toStatic(Grupo* g);
};

