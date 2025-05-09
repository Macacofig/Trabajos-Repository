#include "ConferenciaVirtual.h"

ConferenciaVirtual::ConferenciaVirtual(int numero, long fecha, string link)
	:Conferencia(numero,fecha,"Virtual")
{
	this->link = link;
}

ConferenciaVirtual::~ConferenciaVirtual()
{
}

string ConferenciaVirtual::toJson()
{
	stringstream ss;
	ss << "{\"numero\":" << numero << ",\"fecha\":" << fecha << ",\"link\":\"" << link
		<< "\",\"instructores\":" << instructores.toJson() << ",\"participantes\":" << participantes.toJson() << "}";
	return ss.str();
}
