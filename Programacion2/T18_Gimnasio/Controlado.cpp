#include "Controlado.h"

Controlado::Controlado(string id)
	:Grupo(id)
{
}

Controlado::~Controlado()
{
}

string Controlado::toJson()
{
	stringstream ss;
	if (cont == 1)
	{
		ss << "{\"id\":\"" << id
			<< "\",\"inscritos\":" << inscritos.toJson(Socio::toStatic)
			<< ",\"sesiones\":" << sesiones.toJson(Sesion::toStatic) << "}";
	}
	else
	{
		ss << "{\"id\":\"" << id
			<< "\",\"inscritos\":" << inscritos.toJson(Socio::toStatic) << "}";
	}
	return ss.str();
}

