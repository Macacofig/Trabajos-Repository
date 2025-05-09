#include "Grupo.h"

Grupo::Grupo(string id)
{
	this->id = id;
	cont = 0;
}

Grupo::~Grupo()
{
}

void Grupo::inscribir(int id)
{
	Socio s1(id);
	Socio* s = SingletonSocios::getInst().getSocios()->buscar(&s1);
	if (s != NULL)
	{
		inscritos.registrar(s);
	}
}

void Grupo::registrarSesion(int fecha)
{
	sesiones.registrar(new Sesion(fecha));
	cont = 1;
}

void Grupo::registrarAsistente(int ci, int fecha)
{
	Socio s(ci);
	Socio* s1 = SingletonSocios::getInst().getSocios()->buscar(&s);
	if (s1 != NULL)
	{
		Sesion se(fecha);
		Sesion* se1= sesiones.buscar(&se);
		if (se1 != NULL)
		{
			se1->getSocios().registrar(s1);
		}
	}
	

}

string Grupo::toJson()
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

string Grupo::toStatic(Grupo* g)
{
	return g->toJson();
}
