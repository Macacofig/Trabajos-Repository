#pragma once
#include "ModClientes.h"
#include "CuentaDepositoPF.h"
class Banco
{
private:
	string nom;
	ModClientes clientes;
public:
	Banco(string nom);
	~Banco();
	ModClientes& getClientes();
	void registrarCliente(Cliente* cli,Cuenta* cu);
	void adicionarCuentaCliente(int ci, Cuenta* cu);
	void eliminarCuentaCliente(int ci, int id);
	string toJson();
	void mostrar();
};

