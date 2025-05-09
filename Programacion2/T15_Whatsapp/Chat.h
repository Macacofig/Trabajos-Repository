#pragma once
#include "ArrayGen.h"
#include "Mensaje.h"
#include "Texto.h"
#include "Archivo.h"
class Chat
{
private:
	long numreceptor;
	ArrayGen<Mensaje> mensajes;
public:
	Chat(long numreceptor);
	~Chat();
	ArrayGen<Mensaje>& getMensajes();
	long getNumReceptor();
	bool operator==(Chat* c);
	string toJson();
	static string toJsonStatic(Chat* c);
};

