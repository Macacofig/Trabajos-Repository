#include "Universidad.h"

Universidad::Universidad(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Universidad::~Universidad()
{
}

void Universidad::registrarConferenciaVirtual(int numero, int fecha, string link)
{
	conferencias.registrarConferenciaVirtual(new ConferenciaVirtual(numero, fecha, link));
}

void Universidad::registrarConferenciaPresencial(int numero, int fecha, string lugar)
{
	conferencias.registrarConferenciaPresencial(new ConferenciaPresencial(numero, fecha, lugar));
}

void Universidad::registrarParticipanteEnConferencia(int numero, Docente* docente)
{
	Conferencia* c = conferencias.buscar(numero);
	if (c != NULL)
	{
		c->getInstructores().registrar(docente);
	}
}

void Universidad::registrarParticipanteEnConferencia(int numero, Estudiante* estudiante)
{
	Conferencia* c = conferencias.buscar(numero);
	if (c != NULL)
	{
		c->getParticipantes().registrar(estudiante);
	}
}

string Universidad::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"direccion\":\"" << direccion
		<< "\",\"conferencias\":" << conferencias.toJson() << "}";
	return ss.str();
}
