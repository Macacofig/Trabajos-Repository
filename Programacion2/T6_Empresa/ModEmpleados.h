#pragma once
#include "Empleado.h"

class ModEmpleados
{
private:
	int ind;
	int tam;
	Empleado** empleados;
public:
	ModEmpleados(int tam);
	~ModEmpleados();
	int getind();
	int gettam();
	void registrar(Empleado* empleado);
	Empleado* buscar(int Ci);
	void ordenar();
	void mostrar();
	string toJson();

};