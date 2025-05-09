#include "Capacitacion.h"

Capacitacion::Capacitacion(int idCap, string NombreArea) 
	:sesiones(CANT_MAX_SE),inscritos(CANT_MAX_EINSCRITOS),instructores(CANT_MAX_EINSTRUCTORES)
{
	this->idCap = idCap;
	this->NombreArea = NombreArea;
}

Capacitacion::~Capacitacion()
{
}

int Capacitacion::getidCap()
{
	return idCap;
}

string Capacitacion::getNombreArea()
{
	return NombreArea;
}

void Capacitacion::setidCap(int idCap)
{
	this->idCap = idCap;
}

void Capacitacion::setNombreArea(string NombreArea)
{
	this->NombreArea = NombreArea;
}

void Capacitacion::mostrar()
{
	cout << "Capacitacion:" << endl;
	cout << toJson();
}

string Capacitacion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"IdCap\":" << idCap << ",";
	ss << "\"NombreArea\":\"" << NombreArea << "\",";
	ss << "\"Inscritos\":" << inscritos.toJson();
	ss << "\"Instructores\":" << inscritos.toJson();
	ss << "\"Sesiones\":" << sesiones.toJson();
	ss << "}";
	return ss.str();
}

void Capacitacion::revisarasistencia(int ci)
{
	Empleado* e = inscritos.buscar(ci);
	Sesion* ses;
	if (e != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			if (ses[i].geteasistieron().buscar(ci) != NULL) 
			{
				cout << "Sesion " << i + 1 << "Empleado:" << e->getNombre()<<" Asistio";
			}
		}
	}

}

ModSesiones& Capacitacion::getsesiones()
{
	return sesiones;
}

ModEmpleados& Capacitacion::getinscritos()
{
	return inscritos;
}

ModEmpleados& Capacitacion::getinstructores()
{
	return instructores;
}

void Capacitacion::empleadosasis(int idSesion, Empleado* emasis)
{
	Sesion* sesion = sesiones.buscar(idSesion);
	if (sesion != NULL)
	{
		sesion->geteasistieron().registrar(emasis);
	}
}

void Capacitacion::instructoresasis(int idSesion, Empleado* insasis)
{
	Sesion* sesion = sesiones.buscar(idSesion); 
	if (sesion != NULL)
	{
		sesion->getinstructores().registrar(insasis);
	}
}

