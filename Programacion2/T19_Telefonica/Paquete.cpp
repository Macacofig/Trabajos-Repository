#include "Paquete.h"

Paquete::Paquete(int saldo, string tipo)
{
	this->saldo = saldo;
	this->tipo = tipo;
}

Paquete::Paquete(string tipo)
{
	this->tipo = tipo;
}

Paquete::~Paquete()
{
}

int Paquete::getSaldo()
{
	return saldo;
}

string Paquete::getTipo()
{
	return tipo;
}

void Paquete::setSaldo(int saldo)
{
	this->saldo = saldo;
}

bool Paquete::operator==(Paquete* p)
{
	return tipo==p->getTipo();
}

string Paquete::toJson()
{
	stringstream ss;
	return ss.str();
}

string Paquete::toStatic(Paquete* p)
{
	return p->toJson();
}
