#include "ExceptionMovBloque.h"

ExceptionMovBloque::ExceptionMovBloque()
{
	stringstream ss;
	ss << "el objeto no puede moverse";
	mensaje = ss.str();
}

ExceptionMovBloque::~ExceptionMovBloque()
{
}

const char* ExceptionMovBloque::what() const
{
	return mensaje.c_str();
}
