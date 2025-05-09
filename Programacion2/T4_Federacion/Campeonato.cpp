#include "Campeonato.h"

Campeonato::Campeonato(string nombrecampeonato, int codcampeonato,string fechacampeonato)
	:partidos(CANT_MAX_PAR),equiposinscritos(CANT_MAX_EQINS)
{
	this->nombrecampeonato = nombrecampeonato;
	this->codcampeonato = codcampeonato;
	this->fechacampeonato = fechacampeonato;
}

Campeonato::~Campeonato()
{
}

string Campeonato::getnombrecampeonato()
{
	return nombrecampeonato;
}

string Campeonato::getfechacampeonato()
{
	return fechacampeonato;
}

int Campeonato::getcodcampeonato()
{
	return codcampeonato;
}

Modpartidos& Campeonato::getpartidos()
{
	return partidos;
}

ModEquiposInscritos& Campeonato::getequiposinscritos()
{
	return equiposinscritos;
}

void Campeonato::mostrar()
{
	cout << "Campeonato:" << endl;
	cout << toJson() << endl;
}

string Campeonato::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"CodigoCampeonato\":" << codcampeonato << ",";
	ss << "\"NombreCampeonato\":\"" << nombrecampeonato << "\",";
	ss<< "\"Partidos\":" << partidos.toJson();
	ss << "\"EquiposInscritos\":" << equiposinscritos.toJson();
	ss << "}";
	return ss.str();
}
