#include "Empresa.h"

Empresa::Empresa(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Empresa::~Empresa()
{
}

ModClientes& Empresa::getClientes()
{
	return clientes;
}

void Empresa::registrarCliente(string nombre, double saldo)
{
	clientes.registrar(new Cliente(nombre, saldo));
}

void Empresa::registrarPaquete(string nombre, PaqueteMinutos* pm)
{
	Cliente* c = clientes.buscar(nombre);
	if (c != NULL)
	{
		c->getPaquetes().registrar(pm);
	}
}

void Empresa::registrarPaquete(string nombre, PaqueteSMS* psms)
{
	Cliente* c = clientes.buscar(nombre);
	if (c != NULL)
	{
		c->getPaquetes().registrar(psms);
	}
}

void Empresa::registrarLlamada(string nombre, int id, long fecha, int durmin)
{
	Cliente* c = clientes.buscar(nombre);
	if (c != NULL)
	{
		c->ejecutarAccion(new Llamada(id, fecha, durmin));
	}
}

void Empresa::registrarSMS(string nombre, int id, long fecha)
{
	Cliente* c = clientes.buscar(nombre);
	if (c != NULL)
	{
		c->ejecutarAccion(new SMS(id, fecha));
	}
}

string Empresa::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"dirreccion\":\""<<direccion
		<<"\",\"clientes\":"<<clientes.toJson()<<"}";
	return ss.str();
}
