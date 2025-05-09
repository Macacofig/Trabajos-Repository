#pragma once
#include "ModClientes.h"
class Empresa
{
private:
	string nombre;
	string direccion;
	ModClientes clientes;
public:
	Empresa(string nombre, string direccion);
	~Empresa();
	ModClientes& getClientes();
	void registrarCliente(string nombre, double saldo);
	void registrarPaquete(string nombre, PaqueteMinutos* pm);
	void registrarPaquete(string nombre, PaqueteSMS* psms);
	void registrarLlamada(string nombre, int id, long fecha, int durmin);
	void registrarSMS(string nombre, int id, long fecha);
	string toJson();
};

