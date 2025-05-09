#include "Usuario.h"

Usuario::Usuario(string nombre, int saldoprin)
{
	this->nombre = nombre;
	this->saldoprin = saldoprin;
}

Usuario::Usuario(string nombre)
{
	this->nombre = nombre;
}

Usuario::~Usuario()
{
}

string Usuario::getNombre()
{
	return nombre;
}

ListaGen<Paquete>& Usuario::getPaquetes()
{
	return paquetes;
}

ListaGen<Accion>& Usuario::getAcciones()
{
	return acciones;
}

void Usuario::setSaldo(int saldo)
{
	this->saldoprin = saldo;
}

bool Usuario::operator==(Usuario* u)
{
	return nombre==u->getNombre();
}

void Usuario::ejecutarAccion(Llamada* llamada)
{
	Llamada* l = llamada;
	int cont = l->getDurmin();
	int total;
	int resto = 0;
	PaqueteMinutos* pm = (PaqueteMinutos*)paquetes.buscar(new Paquete("minutos"));
	string nom = getNombre();
	if (pm->getSaldo() > 0)
	{
		for (int i = 1; i <= cont; i++)
		{
			pm->setSaldo(pm->getSaldo() - 1);
			resto = i;
			if (pm->getSaldo() == 0)
			{
				i = cont;
			}
		}
	}
	total = cont - resto;
	if (total > saldoprin)
	{
		throw CException(nom, "llamada", acciones.getCont()+1);
	}
	else
	{
		acciones.registrar(llamada);
		setSaldo(saldoprin - total);
	}
}

void Usuario::ejecutarAccion(Descarga* descarga)
{
	Descarga* l = descarga;
	int cont = l->getMegas();
	int total;
	int resto = 0;
	PaqueteMegas* pm = (PaqueteMegas*)paquetes.buscar(new Paquete("megas"));
	string nom = getNombre();
	if (pm->getSaldo() > 0)
	{
		for (int i = 1; i <= cont; i++)
		{
			pm->setSaldo(pm->getSaldo() - 1);
			resto = i;
			if (pm->getSaldo() == 0)
			{
				i = cont;
			}
		}
	}
	total = cont - resto;
	if (total > saldoprin)
	{
		throw CException(nom, "descarga", acciones.getCont()+1);
	}
	else
	{
		acciones.registrar(descarga);
		setSaldo(saldoprin - total);
	}
}

string Usuario::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"saldo\":" << saldoprin 
		<< ",\"paquetes\":" << paquetes.toJson(Paquete::toStatic) 
		<< ",\"detalle\":" << acciones.toJson(Accion::toStatic) << "}";
	return ss.str();
}

string Usuario::toStatic(Usuario* u)
{
	return u->toJson();
}
