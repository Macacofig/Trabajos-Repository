#pragma once
#include "Usuario.h"
#include "ListaGen.h"
class Telefonica
{
private:
	string nombre;
	string direccion;
	ListaGen<Usuario> clientes;
public:
	Telefonica(string nombre, string direccion);
	~Telefonica();
	ListaGen<Usuario>& getClientes();
	void registrarCliente(string nom, int saldoprin);
	void registrarPaquete(string nomus, Paquete* paquete);
	void registrarLlamada(string nomus, int id, int fecha, int durmin);
	void registrarDescarga(string nomus, int id, int fecha, int megas);
	string toJson();
};

