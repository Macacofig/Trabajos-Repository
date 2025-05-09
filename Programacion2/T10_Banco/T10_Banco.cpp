/*
Se desea desarrollar un sistema bancario que brinde al usuario las siguientes funcionalidades:

Registrar clientes, al registrar un cliente el sistema debe registrar también una cuenta.
Eliminar clientes, al eliminar un cliente el sistema debe eliminar todas las cuentas asociadas al cliente.
Adicionar cuentas a clientes existentes.
Eliminar una cuenta de un determinado cliente.

Ver un reporte de un cliente y sus cuentas, al mostrar una cuenta se debe desplegar toda su información(incluyendo las transacciones realizadas).
Un cliente puede tener varias cuentas de distintos tipos, las mismas están compuestas por: identificador único y saldo. Entre los tipos de cuentas tenemos:

Caja de ahorro. - La cual cuenta con un costo de mantenimiento mensual y permite realizar las siguientes operaciones:
Deposito
Retiro
Actualización, resta del saldo de la cuenta el costo por mantenimiento.

Cuenta corriente. - La cual cuenta con interés anual y permite realizar las siguientes operaciones:
Deposito
Retiro
Actualización, suma al saldo de la cuenta el monto por el interés mensual.

Cuenta depósito a plazo fijo. - La cual tiene una fecha de inicio, una fecha de finalización, interés anual y solamente permite realizar:
Actualización, suma al saldo de la cuenta un monto de acuerdo con el interés anual.
Nota.-

Un cliente puede tener más de una cuenta, pero una cuenta pertenece a una sola persona.
Se debe tener registro de todas las transacciones realizadas sobre las cuentas.
*/

#include "Banco.h"
void ejemplo1()
{
	/*
	* Error
	* Cuenta cuenta(1,100);
	* no se crea cuentas de tipo abstracto
	*/
}
int main()
{
	Banco b("Union");
	b.getClientes().registrar(new Cliente(1, "Mateo"));
	b.getClientes().registrar(new Cliente(2, "Juan"));
	b.mostrar();
}