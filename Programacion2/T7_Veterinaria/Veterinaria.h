#pragma once
#include "ModClientes.h"
#include "ModAtenciones.h"
#include "ModReservas.h"
#include "ModMascotas.h"
#define C_M_MASC 10
#define C_M_ATEN 10
#define C_M_CLI 10
#define C_M_RES 10
class Veterinaria
{
private:
	ModClientes clientes;
	ModAtenciones atenciones;
	ModReservas reservas;
	ModMascotas mascotas;
public:
	Veterinaria();
	~Veterinaria();
	string toString();

	void registrarCliente(Cliente* cli);
	void registrarMascota(int ci, Mascota* mas);
	void registrarAtencion(Atencion* aten);
	void registrarReserva(int id,int codigo,int ci,string nombre);
};

