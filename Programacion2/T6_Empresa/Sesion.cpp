#include "Sesion.h"

Sesion::Sesion(int idSesion, string fecha,string hora,string lugar)
	:easistieron(CANT_MAX_EINSCRITOS),instructores(CANT_MAX_EINSTRUCTORES)
{
	this->idSesion = idSesion;
	this->fecha = fecha;
	this->hora = fecha;
	this->lugar = lugar;
}

Sesion::~Sesion()
{
}

int Sesion::getidSesion()
{
	return idSesion;
}

string Sesion::getfecha()
{
	return fecha;
}

string Sesion::gethora()
{
	return hora;
}

string Sesion::getlugar()
{
	return lugar;
}

void Sesion::mostrar()
{
	cout << "Sesion:" << endl;
	cout << toJson();
}

string Sesion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"IdSesion\":" << idSesion<< ",";
	ss << "\"Fecha\":\"" << fecha << "\", ";
	ss << "\"Hora\":\"" << hora << "\", ";
	ss << "\"Lugar\":\"" << lugar << "\", ";
	ss << "\"Inscritos\":" << easistieron.toJson();
	ss << "\"Instructores\":" << instructores.toJson();
	ss << "}";
	return ss.str();
}

ModEmpleados& Sesion::geteasistieron()
{
	return easistieron;
}

ModEmpleados& Sesion::getinstructores()
{
	return instructores;
}
