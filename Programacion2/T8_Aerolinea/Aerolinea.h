#pragma once
#include "ModVuelos.h"
#include "ModPersonas.h"
#include "ModAviones.h"
class Aerolinea
{
private:
	string nombre;
	int CMCli;
	int CMAvi;
	int CMVue;
	ModPersonas clientes;
	ModAviones aviones;
	ModVuelos vuelos;
public:
	Aerolinea(string nombre, int CMCli, int CMAvi, int CMVue);
	~Aerolinea();
	ModAviones& getAviones();
	ModPersonas& getClientes();
	ModVuelos& getVuelos();
	void registrarVuelo(int numero, int placa);
	void registrarPasajeroEnVuelo(int numero,int fila,int columna,int ci);
	string toJson();
};

