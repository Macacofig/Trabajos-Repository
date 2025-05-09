/*
Una empresa telefonica desea un sistema para el control de paquetes de llamadas e internet que ofrece
a sus clientes, se debe considerar las siguientes funcionalidades:
- Registrar usuarios.
- Registrar uso de megas.
- Registrar llamadas
- Registrar cobros sobre los paquetes y el saldo principal
Nota:
- Costo de mega 1 Bs.
- Costo de minuto de llamada 1 Bs.
*/

#include "Telefonica.h"//Empresa
//Crear Telefonica(nombre, direccion)
Telefonica viva("viva", "Pedro Blanco");//Empresa

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Requerido" << endl;
	cout << "{\"nombre\":\"juan\",\"saldo\":5,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"megas\",\"saldo megas\":20}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}" << endl;
	string error;
	// Crear usuario(nombre, saldo Bs)
	Usuario usuario("juan", 10);

	try {

		// Registrar paquetes
		usuario.getPaquetes().registrar(new PaqueteMinutos(5));
		usuario.getPaquetes().registrar(new PaqueteMegas(20));
		// Realizar llamadas(id, fecha, duracion llamada en minutos)
		usuario.ejecutarAccion(new Llamada(1, 20220101, 5));
		usuario.ejecutarAccion(new Llamada(2, 20220101, 5));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = usuario.toJson();
	cout << "Obtenido" << endl;
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"juan\",\"saldo\":5,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"megas\",\"saldo megas\":20}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	cout << "Esperado" << endl;
	cout << "" << endl;
	cout << "{\"nombre\":\"juan\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":5},{\"tipo\":\"megas\",\"saldo megas\":8}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":5,\"fecha\":20220101,\"tipo\":\"descarga\"}]}" << endl;
	string error;
	// Crear usuario(nombre, saldo)
	Usuario usuario("juan", 10);
	try {
		// Registrar paquetes
		usuario.getPaquetes().registrar(new PaqueteMinutos(5));
		usuario.getPaquetes().registrar(new PaqueteMegas(20));
		// Usuario descarga datos(id, megas, fecha)
		usuario.ejecutarAccion(new Descarga(1, 2, 20220101)); // id,fecha,megas
		usuario.ejecutarAccion(new Descarga(2, 2, 20220101));
		usuario.ejecutarAccion(new Descarga(3, 2, 20220101));
		usuario.ejecutarAccion(new Descarga(4, 2, 20220101));
		usuario.ejecutarAccion(new Descarga(5, 4, 20220101));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = usuario.toJson();
	cout << "Obtenido" << endl;
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"juan\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":5},{\"tipo\":\"megas\",\"saldo megas\":8}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":5,\"fecha\":20220101,\"tipo\":\"descarga\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout << "Esperado" << endl;
	cout << "saldo insuficiente juan no pudo realizar la descarga 5" << endl;
	cout << endl;
	cout << "{\"nombre\":\"juan\",\"saldo\":0,\"paquetes\":[{\"tipo\":\"megas\",\"saldo megas\":3}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"descarga\"}]}" << endl;
	string error;
	// Crear usuario(nombre, saldo)
	Usuario usuario("juan", 0);
	try {
		// Registrar paquetes
		usuario.getPaquetes().registrar(new PaqueteMegas(10));
		// Usuario descarga datos(id, megas, fecha)
		usuario.ejecutarAccion(new Descarga(1, 2, 20220101));
		usuario.ejecutarAccion(new Descarga(2, 2, 20220101));
		usuario.ejecutarAccion(new Descarga(3, 3, 20220101));
		usuario.ejecutarAccion(new Descarga(4, 3, 20220101));
		usuario.ejecutarAccion(new Descarga(5, 2, 20220101));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = usuario.toJson();
	cout << "Obtenido" << endl;
	cout << result << endl;
	cout << endl;
	cout << error << endl;
	if (error == "saldo insuficiente juan no pudo realizar la descarga 5" && result == "{\"nombre\":\"juan\",\"saldo\":0,\"paquetes\":[{\"tipo\":\"megas\",\"saldo megas\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"descarga\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta4()
{
	cout << "----Pregunta 4----" << endl;
	cout << "Esperado" << endl;
	cout << "saldo insuficiente pedro no pudo realizar la llamada 3" << endl;
	cout << endl;
	cout << "{\"nombre\":\"pedro\",\"saldo\":0,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":2,\"fecha\":20220101,\"minutos\":10,\"tipo\":\"llamada\"}]}" << endl;

	string error;
	// Crear usuario(nombre, saldo)
	Usuario usuario("pedro", 10);
	try {
		// Registrar paquetes
		usuario.getPaquetes().registrar(new PaqueteMinutos(5));
		// Realizar llamadas(id, fecha, duracion llamada en minutos)
		usuario.ejecutarAccion(new Llamada(1, 20220101, 5));
		usuario.ejecutarAccion(new Llamada(2, 20220101, 10));
		usuario.ejecutarAccion(new Llamada(3, 20220101, 5));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = usuario.toJson();
	cout << "Obtenido" << endl;
	cout << result << endl;
	cout << endl;
	cout << error << endl;
	if (error == "saldo insuficiente pedro no pudo realizar la llamada 3" && result == "{\"nombre\":\"pedro\",\"saldo\":0,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":2,\"fecha\":20220101,\"minutos\":10,\"tipo\":\"llamada\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta5()
{
	cout << "----Pregunta 5----" << endl;
	cout << "Esperado" << endl;
	cout << "{\"nombre\":\"viva\",\"dirreccion\":\"Pedro Blanco\",\"clientes\":[{\"nombre\":\"juan\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"megas\",\"saldo megas\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"descarga\"}]},{\"nombre\":\"jose\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"megas\",\"saldo megas\":10}],\"detalle\":[{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}]}" << endl;
	cout << "" << endl;
	string error;
	// Juan (saldo=10 ,minutos=0 ,megas=0 )
	// Jose (saldo=10 ,minutos=0 ,megas=10 )
	//
	try {
		// Registrar usuario
		viva.registrarCliente("juan", 10);
		viva.registrarCliente("jose", 10);
		// Registrar paquetes
		viva.registrarPaquete("juan", new PaqueteMinutos(5));
		viva.registrarPaquete("juan", new PaqueteMegas(20));
		viva.registrarPaquete("jose", new PaqueteMinutos(5));
		viva.registrarPaquete("jose", new PaqueteMegas(10));
		// Realizar llamadas(usuario, id, fecha, duracion llamada en minutos)

		viva.registrarLlamada("juan", 1, 20220101, 5);
		viva.registrarLlamada("jose", 2, 20220101, 5);
		// Usuario descarga datos(nombre, id, fecha, megas)
		viva.registrarDescarga("juan", 3, 20220101, 10); //registrarSMS
		viva.registrarDescarga("juan", 4, 20220101, 10); //registrarSMS
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = viva.toJson();
	cout << "Obtenido" << endl;
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"nombre\":\"viva\",\"dirreccion\":\"Pedro Blanco\",\"clientes\":[{\"nombre\":\"juan\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"megas\",\"saldo megas\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"descarga\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"descarga\"}]},{\"nombre\":\"jose\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"megas\",\"saldo megas\":10}],\"detalle\":[{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta1() + pregunta2() + pregunta3() + pregunta4() + pregunta5();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}