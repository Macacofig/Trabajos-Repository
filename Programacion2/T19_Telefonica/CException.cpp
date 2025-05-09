#include "CException.h"

CException::CException(string nombre, string tipo, int pos)
{
	stringstream ss;
	ss << "saldo insuficiente " << nombre << " no pudo realizar la " << tipo << " " << pos;
	mensj = ss.str();
}

CException::~CException()
{
}

const char* CException::what() const
{
	return mensj.c_str();
}
