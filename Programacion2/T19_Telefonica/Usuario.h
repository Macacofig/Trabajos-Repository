#pragma once
#include "PaqueteMinutos.h"
#include "PaqueteMegas.h"
#include "Llamada.h"
#include "Descarga.h"
#include "ListaGen.h"
#include "CException.h"
class Usuario
{
private:
	string nombre;
	int saldoprin;
	ListaGen<Paquete> paquetes;
	ListaGen<Accion> acciones;
public:
	Usuario(string nombre, int saldoprin);
	Usuario(string nombre);
	~Usuario();
	string getNombre();
	ListaGen<Paquete>& getPaquetes();
	ListaGen<Accion>& getAcciones();
	void setSaldo(int saldo);
	bool operator==(Usuario* u);
	void ejecutarAccion(Llamada* llamada);
	void ejecutarAccion(Descarga* descarga);
	string toJson();
	static string toStatic(Usuario* u);
};

