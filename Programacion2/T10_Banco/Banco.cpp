#include "Banco.h"

Banco::Banco(string nom)
{
	this->nom = nom;
}

Banco::~Banco()
{
}

ModClientes& Banco::getClientes()
{
	return clientes;
}

void Banco::registrarCliente(Cliente* cli, Cuenta* cu)
{
	getClientes().registrar(cli);
	Cliente* c = cli;
	c->getCuentas().registrar(cu);
}

void Banco::adicionarCuentaCliente(int ci, Cuenta* cu)
{
	Cliente* c = clientes.buscar(ci);
	c->getCuentas().registrar(cu);
}

void Banco::eliminarCuentaCliente(int ci, int id)
{
	Cliente* cli = clientes.buscar(ci);
	cli->getCuentas().eliminarCuenta(id);
}

string Banco::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nom << "\",";
	ss << "\"Clientes\":" << clientes.toJson();
	ss << "}";
	return ss.str();
}

void Banco::mostrar()
{
	cout << "Banco:" << endl;
	cout << toJson();
}
