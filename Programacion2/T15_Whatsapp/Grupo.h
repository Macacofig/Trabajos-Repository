#pragma once
#include "ArrayGen.h"
#include "Mensaje.h"
#include "Usuario.h"
class Grupo
{
private:
	string nombre;
	ArrayGen<Mensaje> mensajes;
	ArrayGen<Usuario> integrantes;
public:
	Grupo(string nombre);
	~Grupo();
	bool operator==(Grupo* g);
	string toJson();
	string getNombreGrupo();
	ArrayGen<Usuario>& getIntegrantes();
	ArrayGen<Mensaje>& getMensajes();
	static string StaticToJson(Grupo* g);
};

