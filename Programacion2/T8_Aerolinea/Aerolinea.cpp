#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre, int CMCli, int CMAvi, int CMVue)
	:clientes(CMCli),aviones(CMAvi),vuelos(CMVue)
{
	this->nombre = nombre;
}

Aerolinea::~Aerolinea()
{
}

ModAviones& Aerolinea::getAviones()
{
	return aviones;
}

ModPersonas& Aerolinea::getClientes()
{
	return clientes;
}

ModVuelos& Aerolinea::getVuelos()
{
	return vuelos;
}

void Aerolinea::registrarVuelo(int numero, int placa)
{
	Avion* avion = aviones.buscar(placa);
	if (avion != NULL)
	{
		vuelos.registrarVuelo(new Vuelo(numero, avion));
	}
}

void Aerolinea::registrarPasajeroEnVuelo(int numero, int fila, int columna, int ci)
{
	Persona* cliente = clientes.buscar(ci);
	if (cliente != NULL)
	{
		Vuelo* vuelo = vuelos.buscar(numero);
		if (vuelo != NULL)
		{
			vuelo->registrarPasajero(fila, columna, cliente);
		}
	}
}

string Aerolinea::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"clientes\":"<<clientes.toJson()<<",\"aviones\":"<<aviones.toJson()<<",\"vuelos\":"<<vuelos.toJson()<<"}";
	return ss.str();
}
