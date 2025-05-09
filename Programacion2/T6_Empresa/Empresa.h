#pragma once
#include "ModEmpleados.h"
#include "ModCapacitaciones.h"
#define CANT_MAX_EMP 20
#define CANT_MAX_CAP 20
class Empresa
{
private:
	string NombreEmpresa;
	ModEmpleados empleados;
	ModCapacitaciones capacitaciones;
public:
	Empresa(string NombreEmpresa);
	~Empresa();
	string getNombre();
	void mostrar();
	string toJson();

	ModCapacitaciones& getcapacitaciones();
	ModEmpleados& getempleados();

	void agregarsesion(int idCap,Sesion* ses);
	void inscribirempleados(int idCap,int Ci);
	void inscribirinstructor(int idCap,int Ci);
	void empleadosasis(int idCap, int idSesion, int Ci);
	void instructoresasis(int idCap, int idSesion, int Ci);
};

