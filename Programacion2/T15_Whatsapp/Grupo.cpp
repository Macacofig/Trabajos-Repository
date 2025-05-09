#include "Grupo.h"

Grupo::Grupo(string nombre)
{
	this->nombre = nombre;
}

Grupo::~Grupo()
{
}

bool Grupo::operator==(Grupo* g)
{
	return nombre==g->getNombreGrupo();
}

string Grupo::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre
		<<"\",\"mensajes\":"<<mensajes.toJson(Mensaje::toJsonStatic)
		<<",\"usuarios\":"<<integrantes.toJson(Usuario::toJsonIntegrantes)<<"}";
	return ss.str();

}

string Grupo::getNombreGrupo()
{
	return nombre;
}

ArrayGen<Usuario>& Grupo::getIntegrantes()
{
	return integrantes;
}

ArrayGen<Mensaje>& Grupo::getMensajes()
{
	return mensajes;
}

string Grupo::StaticToJson(Grupo* g)
{
	return g->toJson();
}
