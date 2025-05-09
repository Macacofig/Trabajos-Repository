#include "IndException.h"

IndException::IndException(int ind)
{
	stringstream ss;
	ss << "Error indice invalido:" << ind;
	mensaje = ss.str();
}

IndException::~IndException()
{
}

const char* IndException::what() const
{
	return mensaje.c_str();
}
