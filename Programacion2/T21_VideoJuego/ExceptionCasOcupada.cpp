#include "ExceptionCasOcupada.h"

ExceptionCasOcupada::ExceptionCasOcupada()
{
	stringstream ss;
	ss << "casilla ocupada";
	mensaje = ss.str();
}

ExceptionCasOcupada::~ExceptionCasOcupada()
{
}

const char* ExceptionCasOcupada::what() const
{
	return mensaje.c_str();
}
