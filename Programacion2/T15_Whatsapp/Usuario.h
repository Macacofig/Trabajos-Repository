#pragma once
#include "ArrayGen.h"
#include "Chat.h"
class Usuario
{
private:
	string nombre;
	long telefono;
	ArrayGen<Chat> chats;
public:
	Usuario(long telefono);
	Usuario(long telefono, string nombre);
	~Usuario();
	ArrayGen<Chat>& getChats();
	string getNombre();
	long getTelefono();
	bool operator==(Usuario* u);
	static bool cmpTelefono(Usuario* u1, Usuario* u2);
	void enviarMensaje(Mensaje* m, long num);
	void recibirMensaje(Mensaje* m);
	string toString();
	string toStringgrupos();
	static string toJson(Usuario* u);
	static string toJsonIntegrantes(Usuario* u);
};

