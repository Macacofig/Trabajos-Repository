/*
Implementar un sistema para el control de paquetes de llamadas y SMS que ofrece una empresa 
de telefonia
� Registrar clientes.
� Registrar envio de SMSs.
� Registrar llamadas
� Registrar cobros sobre los paquetes y el saldo principal
*/

#include "Empresa.h"
//Crear empresa(nombre, direccion)
Empresa empresa("tigo", "abcd");
int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Esperado"<<endl;
	cout << "{\"nombre\":\"juan\",\"saldo\":5,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"sms\",\"saldo sms\":3}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}";
	cout << endl;
	// Crear cliente(nombre, saldo)
	Cliente cliente("juan", 10);
	// Registrar paquetes
	cliente.getPaquetes().registrar(new PaqueteMinutos(5));
	cliente.getPaquetes().registrar(new PaqueteSMS(3));
	// Realizar llamadas(id, fecha, duracion llamada en minutos)
	cliente.ejecutarAccion(new Llamada(1, 20220101, 5));
	cliente.ejecutarAccion(new Llamada(2, 20220101, 5));
	string result = cliente.toJson();
	cout << "Resultado"<<endl;
	cout << result << endl;
	if (result == "{\"nombre\":\"juan\",\"saldo\":5,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"sms\",\"saldo sms\":3}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}")
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
	cout << "{\"nombre\":\"juan\",\"saldo\":9.6,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":5},{\"tipo\":\"sms\",\"saldo sms\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":5,\"fecha\":20220101,\"tipo\":\"sms\"}]}";
	cout << endl;
	// Crear cliente(nombre, saldo)
	Cliente cliente("juan", 10);
	// Registrar paquetes
	cliente.getPaquetes().registrar(new PaqueteMinutos(5));
	cliente.getPaquetes().registrar(new PaqueteSMS(3));
	// Enviar SMS(id, fecha)
	cliente.ejecutarAccion(new SMS(1, 20220101));
	cliente.ejecutarAccion(new SMS(2, 20220101));
	cliente.ejecutarAccion(new SMS(3, 20220101));
	cliente.ejecutarAccion(new SMS(4, 20220101));
	cliente.ejecutarAccion(new SMS(5, 20220101));
	string result = cliente.toJson();
	cout << "Resultado" << endl;
	cout << result << endl;
	if (result == "{\"nombre\":\"juan\",\"saldo\":9.6,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":5},{\"tipo\":\"sms\",\"saldo sms\":0}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":2,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":5,\"fecha\":20220101,\"tipo\":\"sms\"}]}")
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
	cout << "{\"nombre\":\"tigo\",\"dirreccion\":\"abcd\",\"clientes\":[{\"nombre\":\"juan\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"sms\",\"saldo sms\":1}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"sms\"}]},{\"nombre\":\"jose\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"sms\",\"saldo sms\":3}],\"detalle\":[{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}]}";
	cout << endl;
	// Registrar cliente
	empresa.registrarCliente("juan", 10);
	empresa.registrarCliente("jose", 10);
	// Registrar paquetes
	empresa.registrarPaquete("juan", new PaqueteMinutos(5));
	empresa.registrarPaquete("juan", new PaqueteSMS(3));
	empresa.registrarPaquete("jose", new PaqueteMinutos(5));
	empresa.registrarPaquete("jose", new PaqueteSMS(3));
	// Realizar llamadas(cliente, id, fecha, duracion llamada en minutos)
	empresa.registrarLlamada("juan", 1, 20220101, 5);
	empresa.registrarLlamada("jose", 2, 20220101, 5);
	// Realizar sms(cliente, id, fecha)
	empresa.registrarSMS("juan", 3, 20220101);
	empresa.registrarSMS("juan", 4, 20220101);
	string result = empresa.toJson();
	cout << "Resultado" << endl;
	cout << result << endl;
	if (result == "{\"nombre\":\"tigo\",\"dirreccion\":\"abcd\",\"clientes\":[{\"nombre\":\"juan\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"sms\",\"saldo sms\":1}],\"detalle\":[{\"id\":1,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"},{\"id\":3,\"fecha\":20220101,\"tipo\":\"sms\"},{\"id\":4,\"fecha\":20220101,\"tipo\":\"sms\"}]},{\"nombre\":\"jose\",\"saldo\":10,\"paquetes\":[{\"tipo\":\"minutos\",\"saldo minutos\":0},{\"tipo\":\"sms\",\"saldo sms\":3}],\"detalle\":[{\"id\":2,\"fecha\":20220101,\"minutos\":5,\"tipo\":\"llamada\"}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta1() + pregunta2() + pregunta3();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}