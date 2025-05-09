#include "ModConferencias.h"\

ModConferencias::ModConferencias()
{
	ind = 0;
	conferencias = new Conferencia * [PS];
}

ModConferencias::~ModConferencias()
{
	delete[] conferencias;
}

Conferencia* ModConferencias::buscar(int numero)
{
	for (int i = 0; i < ind; i++)
	{
		if (conferencias[i]->getNumero() == numero)
		{
			return conferencias[i];
		}
	}
	return NULL;
}

void ModConferencias::registrarConferenciaPresencial(ConferenciaPresencial* conferenciapresencial)
{
	if (ind < PS)
	{
		conferencias[ind] = conferenciapresencial;
		ind++;
	}
}

void ModConferencias::registrarConferenciaVirtual(ConferenciaVirtual* conferenciavirtual)
{
	if (ind < PS)
	{
		conferencias[ind] = conferenciavirtual;
		ind++;
	}
}

string ModConferencias::toJsonConferenciaPresencial()
{
	stringstream ss;
	int cont = 0;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		if (conferencias[i]->getTipo() == "Presencial")
		{
			if (i < ind && cont>0)
			{
				ss << ",";
			}
			ss << conferencias[i]->toJson();
			cont++;
		}
	}
	ss << "]";
	return ss.str();
}

string ModConferencias::toJsonConferenciaVirtual()
{
	stringstream ss;
	int cont = 0;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		if (conferencias[i]->getTipo() == "Virtual")
		{
			if (i < ind && cont>0)
			{
				ss << ",";
			}
			ss << conferencias[i]->toJson();
			cont++;
		}

	}
	ss << "]";
	return ss.str();
}

string ModConferencias::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{	
			ss << conferencias[i]->toJson();
			if (i < ind -1)
			{
				ss << ",";
			}
	}
	ss << "]";
	return ss.str();
}
