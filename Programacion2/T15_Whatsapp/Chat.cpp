#include "Chat.h"

Chat::Chat(long numreceptor)
{
	this->numreceptor = numreceptor;
}

Chat::~Chat()
{
}

ArrayGen<Mensaje>& Chat::getMensajes()
{
	return mensajes;
}

long Chat::getNumReceptor()
{
	return numreceptor;
}

bool Chat::operator==(Chat* c)
{
	return numreceptor==c->getNumReceptor();
}

string Chat::toJson()
{
	stringstream ss;
	ss << "{\"telefono\":" << numreceptor
		<< ",\"mensajes\":" << mensajes.toJson(Mensaje::toJsonStatic) << "}";
	return ss.str();
}

string Chat::toJsonStatic(Chat* c)
{
	return c->toJson();
}
