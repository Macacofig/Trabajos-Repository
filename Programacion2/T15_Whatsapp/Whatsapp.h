#pragma once
#include "Usuario.h"
#include "ArrayGen.h"
#include "Grupo.h"
class Whatsapp
{
private:
	ArrayGen<Usuario> usuarios;
	ArrayGen<Grupo> grupos;
public:
	Whatsapp();
	~Whatsapp();
	ArrayGen<Usuario>& getUsuarios();
	void crearGrupo(string nombre);
	void agregarParticipante(long telf,string nomgrupo);
	void enviarMensaje(string nomgrupo,Mensaje* mensaje);
	void registrarUsuario(long num, string nombre);
	void enviarMensaje(Mensaje* mensaje, long receptor);
	Usuario* getUsuario(long num);
	string usuariosToString();
	string gruposToString();
};

