#pragma once
#include "GeneradorIds.h"
class Equipo
{
private:
	int id;
	string nombre;
	string descripcion;
public:
	Equipo(string nombre);
	Equipo(string nombre, string descripcion);
	~Equipo();
	string getNombre();
	string getDescripcion();
	string toJson();
	bool operator==(Equipo * e);
	static string toJson(Equipo* e);
	static bool cmpNombreASC(Equipo* e1, Equipo* e2);
	static bool cmpNombreDSC(Equipo* e1, Equipo* e2);
	static bool cmpDescASC(Equipo* e1, Equipo* e2);
	static bool cmpDescDSC(Equipo* e1, Equipo* e2);
};

