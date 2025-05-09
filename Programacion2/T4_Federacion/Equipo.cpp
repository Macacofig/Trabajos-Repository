#include "Equipo.h"

Equipo::Equipo(int codequipo,string nombrequipo)
{
	this->codequipo = codequipo;
	this-> nombrequipo=nombrequipo;
}

Equipo::~Equipo()
{
}

int Equipo::getcodequipo()
{
	return codequipo;
}

string Equipo::getnombrequipo()
{
	return nombrequipo;
}

void Equipo::mostrar()
{
	cout << "Equipo:" << endl;
	cout << toJson() << endl;
}

string Equipo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Codequipo\":" << codequipo << ",";
	ss << "\"nombrequipo\":\"" << nombrequipo << "\",";
	ss << "}";
	return ss.str();
}
