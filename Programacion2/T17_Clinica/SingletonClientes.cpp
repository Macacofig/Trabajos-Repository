#include "SingletonClientes.h"

SingletonClientes::SingletonClientes()
{
}

SingletonClientes& SingletonClientes::getInst()
{
    static SingletonClientes instancia;
    return instancia;
}

SingletonClientes::~SingletonClientes()
{
}

ListaGen<Cliente>& SingletonClientes::getClientes()
{
    return clientes;
}

void SingletonClientes::registrar(Cliente* cliente)
{
    clientes.registrar(cliente);
}

Cliente* SingletonClientes::buscar(int ci)
{
    Cliente c1(ci);
    return clientes.buscar(&c1);
}

string SingletonClientes::toString()
{
    stringstream ss;
    clientes.ordenar(Cliente::cmpCIMm);
    ss << clientes.toJson(Cliente::toStatic);
    return ss.str();
}
