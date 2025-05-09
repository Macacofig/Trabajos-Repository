#include "Empresa.h"
int main()
{
	Empresa e("Empresa1");
	e.getempleados().registrar(new Empleado(2, "Leo", "Ref", 10));
	e.getempleados().registrar(new Empleado(1, "Marcos", "Ref", 10));
	e.getempleados().registrar(new Empleado(3, "Leo", "Ref", 10));
	e.getempleados().registrar(new Empleado(4, "Brancos", "Ref", 10));
	e.getcapacitaciones().registrar(new Capacitacion(111, "Meca"));
	e.agregarsesion(111, new Sesion(11, "13/10","10:30","SanBenito"));
	e.inscribirempleados(111, 2);
	e.inscribirempleados(111, 1);
	e.inscribirinstructor(111, 3);
	e.inscribirinstructor(111, 4);
	e.empleadosasis(111, 11, 2);
	e.instructoresasis(111, 11, 1);
	e.mostrar();
}
