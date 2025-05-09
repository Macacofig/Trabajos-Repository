#include "Telefonica.h"

Telefonica::Telefonica(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Telefonica::~Telefonica()
{
}

ListaGen<Usuario>& Telefonica::getClientes()
{
	return clientes;
}

void Telefonica::registrarCliente(string nom, int saldoprin)
{
	clientes.registrar(new Usuario(nom, saldoprin));
}

void Telefonica::registrarPaquete(string nomus, Paquete* paquete)
{
	Usuario u1(nomus);
	Usuario* u = clientes.buscar(&u1);
	if (u != NULL)
	{
		u->getPaquetes().registrar(paquete);
	}
}

void Telefonica::registrarLlamada(string nomus, int id, int fecha, int durmin)
{
	Usuario u1(nomus);
	Usuario* u = clientes.buscar(&u1);
	if (u != NULL)
	{
		u->ejecutarAccion(new Llamada(id, fecha, durmin));
	}

}

void Telefonica::registrarDescarga(string nomus, int id, int fecha, int megas)
{
	Usuario u1(nomus);
	Usuario* u = clientes.buscar(&u1);
	if (u != NULL)
	{
		u->ejecutarAccion(new Descarga(id, megas, fecha));
	}
}

string Telefonica::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"dirreccion\":\"" << direccion
		<< "\",\"clientes\":" << clientes.toJson(Usuario::toStatic) << "}";
	return ss.str();
}
