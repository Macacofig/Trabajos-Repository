#include "Whatsapp.h"

Whatsapp::Whatsapp()
{
}

Whatsapp::~Whatsapp()
{
}

ArrayGen<Usuario>& Whatsapp::getUsuarios()
{
	return usuarios;
}

void Whatsapp::crearGrupo(string nombre)
{
	grupos.registrar(new Grupo(nombre));
}

void Whatsapp::agregarParticipante(long telf, string nomgrupo)
{
	Grupo g1(nomgrupo);
	Grupo* g = grupos.buscar(&g1);
	Usuario u(telf);
	Usuario* u1 = usuarios.buscar(&u);
	if (g != NULL)
	{
		g->getIntegrantes().registrar(u1);
	}
}

void Whatsapp::enviarMensaje(string nomgrupo, Mensaje* mensaje)
{
	Grupo g1(nomgrupo);
	Grupo* g = grupos.buscar(&g1);
	if (g != NULL)
	{
		g->getMensajes().registrar(mensaje);
	}
}

void Whatsapp::registrarUsuario(long num, string nombre)
{
	usuarios.registrar(new Usuario(num, nombre));
}

void Whatsapp::enviarMensaje(Mensaje* mensaje, long receptor)
{
	Usuario u11(mensaje->getNumero());
	Usuario u12(receptor);
	Usuario* u1 = usuarios.buscar(&u11);
	Usuario* u2 = usuarios.buscar(&u12);
	if (u1 != NULL)
	{
		u1->enviarMensaje(mensaje, receptor);
		u2->recibirMensaje(mensaje);
	}
}

Usuario* Whatsapp::getUsuario(long num)
{
	Usuario u11(num);
	Usuario* u = usuarios.buscar(&u11);
	return u;
}

string Whatsapp::usuariosToString()
{
	stringstream ss;
	usuarios.ordenar(Usuario::cmpTelefono);
	ss << "{\"usuarios\":"<<usuarios.toJson(Usuario::toJson)<<"}";
	return ss.str();
}

string Whatsapp::gruposToString()
{
	stringstream ss;
	usuarios.ordenar(Usuario::cmpTelefono);
	ss << "{\"grupos\":"<<grupos.toJson(Grupo::StaticToJson)<<"}";
	return ss.str();
}
