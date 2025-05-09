#include "Funcion.h"

Funcion::Funcion(int id, string nombre, int filas, int columnas)
	:sala(filas,columnas)
{
	this->id = id;
	this->nombre = nombre;
	sala.inicializar();
}

Funcion::Funcion(int id)
	:sala(0, 0)
{
	this->id = id;
}

Funcion::~Funcion()
{
}

int Funcion::getid()
{
	return id;
}

string Funcion::toString()
{
	stringstream ss;
	ss << "{\"id\":" << id << ",\"pelicula\":\"" << nombre
		<< "\",\"sala\":" <<sala.toString(Cliente::toStatic,"persona") << "}";
	return ss.str();
}

string Funcion::toStatic(Funcion* f)
{
	return f->toString();
}

bool Funcion::operator==(Funcion* f)
{
	return id==f->getid();
}

void Funcion::registrarEnSala(Cliente* c, int fil, int col)
{
	Cliente* c1 = SingleClientes::getInst().getClientes()->buscar(c);
	if (c1 != NULL)
	{
		sala.registrar(c1, fil, col);
	}
}
