#include "ConferenciaPresencial.h"

ConferenciaPresencial::ConferenciaPresencial(int numero, long fecha, string lugar)
	:Conferencia(numero,fecha,"Presencial")
{
	this->lugar = lugar;
}

ConferenciaPresencial::~ConferenciaPresencial()
{
}

string ConferenciaPresencial::toJson()
{
	stringstream ss;
	ss << "{\"numero\":" << numero << ",\"fecha\":" << fecha << ",\"lugar\":\"" << lugar 
		<< "\",\"instructores\":"<<instructores.toJson()<<",\"participantes\":"<<participantes.toJson()<<"}";
	return ss.str();
}
