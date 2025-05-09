#include "Empresa.h"

Empresa::Empresa(string NombreEmpresa) :empleados(CANT_MAX_EMP),capacitaciones(CANT_MAX_CAP)
{
	this->NombreEmpresa = NombreEmpresa;
}

Empresa::~Empresa()
{
}

string Empresa::getNombre()
{
	return NombreEmpresa;
}

void Empresa::mostrar()
{
	cout << "Empresa:"<<endl;
	cout << toJson();
}

string Empresa::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"NombreEmpresa\":\"" << NombreEmpresa << "\",";
	ss << "\"Empleados\":" << empleados.toJson();
	ss << "\"Capacitaciones\":" << capacitaciones.toJson(); 
	ss << "}";
	return ss.str();
}

ModCapacitaciones& Empresa::getcapacitaciones()
{
	return capacitaciones;
}

ModEmpleados& Empresa::getempleados()
{
	return empleados;
}

void Empresa::agregarsesion(int idCap, Sesion* ses) 
{
	Capacitacion* capacitacion = capacitaciones.buscar(idCap); 
	if (capacitacion != NULL)
	{
		capacitacion->getsesiones().registrar(ses);
	}
}

void Empresa::inscribirempleados(int idCap,int Ci)
{
	Capacitacion* capacitacion = capacitaciones.buscar(idCap);
	if (capacitacion != NULL)
	{
		Empleado* empleado = empleados.buscar(Ci);
		if (empleado != NULL)
		{
			capacitacion->getinscritos().registrar(empleado);
		}
	}
}

void Empresa::inscribirinstructor(int idCap, int Ci)
{
	Capacitacion* capacitacion = capacitaciones.buscar(idCap); 
	if (capacitacion != NULL) 
	{
		Empleado* empleado = empleados.buscar(Ci); 
		if (empleado != NULL) 
		{
			capacitacion->getinstructores().registrar(empleado); 
		}
	}
}

void Empresa::empleadosasis(int idCap, int idSesion, int Ci)
{
	Capacitacion* capacitacion = capacitaciones.buscar(idCap);
	if (capacitacion != NULL)
	{
		Empleado* empleado = empleados.buscar(Ci);
		if (empleado != NULL)
		{
			capacitacion->empleadosasis(idSesion, empleado); 
		}
	}
}

void Empresa::instructoresasis(int idCap, int idSesion, int Ci)
{
	Capacitacion* capacitacion = capacitaciones.buscar(idCap); 
	if (capacitacion != NULL) 
	{ 
		Empleado* empleado = empleados.buscar(Ci); 
		if (empleado != NULL) 
		{
			capacitacion->instructoresasis(idSesion, empleado); 
		}
	}
}
