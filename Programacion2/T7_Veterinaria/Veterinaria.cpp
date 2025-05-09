#include "Veterinaria.h"

Veterinaria::Veterinaria() 
	:clientes(C_M_CLI),atenciones(C_M_ATEN),reservas(C_M_RES),mascotas(C_M_MASC)
{
}

Veterinaria::~Veterinaria()
{
}

string Veterinaria::toString()
{
	stringstream ss;
	ss << "{\"clientes\":"<<clientes.toString()
		<<",\"atenciones\":"<<atenciones.toString()
		<<",\"reservas\":"<<reservas.toString()<<"}";
	return ss.str();
}

void Veterinaria::registrarCliente(Cliente* cli)
{
	clientes.registar(cli);
}

void Veterinaria::registrarMascota(int ci, Mascota* mas)
{
	Cliente* cliente = clientes.buscar(ci);
	if (cliente != NULL)
	{
		cliente->getMascotas().registar(mas);
	}
}

void Veterinaria::registrarAtencion(Atencion* aten)
{
	atenciones.registar(aten);
}

void Veterinaria::registrarReserva(int id, int codigo, int ci, string nombre)
{
	Atencion* atencion = atenciones.buscar(codigo);
	if (atencion != NULL)
	{
		Cliente* cliente = clientes.buscar(ci);
		if (cliente != NULL)
		{
			Mascota* mascota= cliente->getMascotas().buscar(nombre);
			
			if (mascota != NULL)
			{
				reservas.registar(new Reserva(id, atencion, cliente, mascota));
			}
			else
			{
				cout << "Mascota no encontrada" << endl;
			}
		}
		else
		{
			cout << "Cliente no encontrado"<<endl;
		}
		
	}
	else
	{
		cout << "Atencion no encontrada"<<endl;
	}
	

}
