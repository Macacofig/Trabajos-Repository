#include "Usuario.h"

Usuario::Usuario(long telefono)
{
	this->telefono = telefono;
}

Usuario::Usuario(long telefono, string nombre)
{
	this->telefono = telefono;
	this->nombre = nombre;
}

Usuario::~Usuario()
{
}

ArrayGen<Chat>& Usuario::getChats()
{
	return chats;
}

string Usuario::getNombre()
{
	return nombre;
}

long Usuario::getTelefono()
{
	return telefono;
}

bool Usuario::operator==(Usuario* u)
{
	return telefono==u->getTelefono();
}

bool Usuario::cmpTelefono(Usuario* u1, Usuario* u2)
{
	return u1->getTelefono() < u2->getTelefono();
}

void Usuario::enviarMensaje(Mensaje* m, long num)
{
	Chat c(num);
	Chat* c1=chats.buscar(&c);
	if (c1 != NULL)
	{
		c1->getMensajes().registrar(m);
	}
	else
	{
		Chat* c2 = new Chat(num);
		chats.registrar(c2);
		c2->getMensajes().registrar(m);
	}
}

void Usuario::recibirMensaje(Mensaje* m)
{
	Chat c(m->getNumero());
	Chat* c1 = chats.buscar(&c);
	if (c1 != NULL)
	{
		c1->getMensajes().registrar(m);
	}
	else
	{
		Chat* c2 = new Chat(m->getNumero());
		chats.registrar(c2);
		c2->getMensajes().registrar(m);
	}
}

string Usuario::toString()
{
	stringstream ss;
	ss << "{\"telefono\":" << telefono << ",\"nombre\":\"" << nombre 
		<< "\",\"chats\":"<<chats.toJson(Chat::toJsonStatic)<<"}";
	return ss.str();
}

string Usuario::toStringgrupos()
{
	stringstream ss;
	ss << "{\"telefono\":" << telefono << ",\"nombre\":\"" << nombre << "\"}";
	return ss.str();
}

string Usuario::toJson(Usuario* u)
{
	return u->toString();
}

string Usuario::toJsonIntegrantes(Usuario* u)
{
	return u->toStringgrupos();
}
