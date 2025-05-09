#include "Clinica.h"

Clinica::Clinica()
{
}

Clinica::~Clinica()
{
}

ListaGen<Atencion>& Clinica::getAtenciones()
{
	return atenciones;
}
void Clinica::registrarAtencion(Atencion* atencion)
{
	atenciones.registrar(atencion);
}

void Clinica::registrarReservaSimple(int idReserva, int codigoAtencion, int ciCliente, string nombreMascota)
{
	Cliente* c = SingletonClientes::getInst().buscar(ciCliente);
	if (c != NULL)
	{
		Mascota m1(nombreMascota);
		Mascota* m = c->getMascotas().buscar(&m1);
		if (m != NULL)
		{
			Atencion a1(codigoAtencion);
			Atencion* a = atenciones.buscar(&a1);
			if (a != NULL)
			{
				reservas.registrar(new ReservaSimple(idReserva, c, m, a));
			}
		}
	}
}

void Clinica::registrarReservaMultiple(int idReserva, int codigoAtencion1, int codigoAtencion2, int ciCliente, string nombreMascota)
{
	Cliente* c = SingletonClientes::getInst().buscar(ciCliente);
	if (c != NULL)
	{
		Mascota m1(nombreMascota);
		Mascota* m = c->getMascotas().buscar(&m1);
		if (m != NULL)
		{
			Atencion a(codigoAtencion1);
			Atencion b(codigoAtencion2);
			Atencion* a1 = atenciones.buscar(&a);
			Atencion* a2 = atenciones.buscar(&b);
			if (a1 != NULL && a2 != NULL)
			{
				reservas.registrar(new ReservaMultiple(idReserva, c, m,a1,a2));
			}
		}
	}
}

string Clinica::toString()
{
	stringstream ss;
	atenciones.ordenar(Atencion::CMPmM);
	ss << "{\"atenciones\":" << atenciones.toJson(Atencion::toStatic)
		<< ",\"reservas\":" << reservas.toJson(Reserva::toStatic) << "}";
	return ss.str();
}
