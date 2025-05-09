#pragma once
#include "ModSesiones.h"
#include "ModEmpleados.h"
#define CANT_MAX_EINSCRITOS 10
#define CANT_MAX_EINSTRUCTORES 10
#define CANT_MAX_SE 5
class Capacitacion
{
private:
	int idCap;
	string NombreArea;
	ModSesiones sesiones;
	ModEmpleados inscritos;
	ModEmpleados instructores;
public:
	Capacitacion(int idCap, string NombreArea);
	~Capacitacion();
	int getidCap();
	string getNombreArea();
	void setidCap(int idCap);
	void setNombreArea(string NombreArea);
	void mostrar();
	string toJson();
	void revisarasistencia(int ci);

	ModSesiones& getsesiones();
	ModEmpleados& getinscritos();
	ModEmpleados& getinstructores();
	void empleadosasis(int idSesion, Empleado* emasis);
	void instructoresasis(int idSesion, Empleado* insasis);
};

