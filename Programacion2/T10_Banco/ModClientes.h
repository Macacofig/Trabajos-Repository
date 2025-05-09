#pragma once
#include "Cliente.h"
#define CLS 10
class ModClientes
{
private:
	int ind;
	Cliente** clientes;
public:
	ModClientes();
	~ModClientes();
	void registrar(Cliente* cliente);
	Cliente* buscar(int ci);
	void eliminar(int ci);
	string toJson();
};

