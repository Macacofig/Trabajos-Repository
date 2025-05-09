#include "Cliente.h"

Cliente::Cliente(string nombre, double saldo)
{
	this->nombre = nombre;
	this->saldo = saldo;
}

Cliente::~Cliente()
{
}

double Cliente::getSaldo()
{
	return saldo;
}

void Cliente::setSaldo(double saldo)
{
	this->saldo = saldo;
}

ModAcciones& Cliente::getAcciones()
{
	return acciones;
}

ModPaquetes& Cliente::getPaquetes()
{
	return paquetes;
}

string Cliente::getNombre()
{
	return nombre;
}

void Cliente::ejecutarAccion(Llamada* llamada)
{
	acciones.registrar(llamada);
	Llamada* l = llamada;
	int cont = l->getDurmin();
	int total;
	int resto=0;
	PaqueteMinutos* pm = paquetes.buscar("minutos");
	if (pm->getMinutos() > 0)
	{
		for (int i = 1; i <= cont; i++)
		{
			pm->setMinutos(pm->getMinutos() - 1);
			resto = i;
			if (pm->getMinutos() == 0)
			{
				i = cont;
			}
		}
	}
	total = cont - resto;
	setSaldo(saldo - total);
}

void Cliente::ejecutarAccion(SMS* sms)
{
	acciones.registrar(sms);
	PaqueteSMS* psms = paquetes.buscars("sms");
	if (psms->getSMS() > 0)
	{
		psms->setSMS(psms->getSMS() - 1);
	}
	else
	{
		setSaldo(saldo - 0.2);
	}
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"saldo\":"<<saldo
		<<",\"paquetes\":"<<paquetes.toJson()
		<<",\"detalle\":"<<acciones.toJson()<<"}";
	return ss.str();
}
