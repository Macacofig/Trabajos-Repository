#pragma once
#include "ListaGen.h"
#include "Atencion.h"
#include "AtencionMedica.h"
#include "AtencionPeluqueria.h"
#include "Cliente.h"
#include "Reserva.h"
#include "ReservaSimple.h"
#include "ReservaMultiple.h"
#include "SingletonClientes.h"
class Clinica
{
private:
	ListaGen<Atencion> atenciones;
	ListaGen<Cliente> clientes;
	ListaGen<Reserva> reservas;
public:
	Clinica();
	~Clinica();
	ListaGen<Atencion>& getAtenciones();
	void registrarAtencion(Atencion* atencion);
	void registrarReservaSimple(int idReserva, int codigoAtencion, int ciCliente, string nombreMascota);
	void registrarReservaMultiple(int idReserva, int codigoAtencion1, int codigoAtencion2, int ciCliente, string nombreMascota);
	string toString();
};

