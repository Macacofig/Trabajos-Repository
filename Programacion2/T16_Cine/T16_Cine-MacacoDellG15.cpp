/*Un Sala de Cine desea implementar un programa que permita vender asientos
para cada una de las funciones que proyecta. La sala cuenta
con un numero de filas y un número de asientos por fila.
Cada función cuenta con los detalles de la película a proyectarse.
El sistema debe brindar al usuario las siguientes funcionalidades:
• Registrar y mostrar clientes
• Registrar y mostrar funciones
• Vender boletos para una función determinada (Agregar al cliente a un asiento)*/

#include "SalaCine.h"
#include "Matriz.h"
#include "Adulto.h"
#include "Menor.h"
int test1()
{
	
	cout << "----test 1----" << endl;
	//Creamos una matriz de clientes con 4 filas y 4 columnas
	Matriz<Cliente*> m(4, 4);
	//Construimos clientes(ci, nombre)
	//m[0][0]
	m[0][0] = new Adulto(10001, "Juan Perez");
	m[1][1] = new Menor(10002, "Maria Vargas");
	m[2][2] = new Adulto(10003, "Pedro Rodriguez");
	cout << m[0][0]->toString() << endl;
	cout << m[1][1]->toString() << endl;
	cout << m[2][2]->toString() << endl;
	if (m[0][0]->toString() == "{\"tipo\":\"adulto\",\"ci\":10001,\"nombre\":\"Juan Perez\"}" &&
		m[1][1]->toString() == "{\"tipo\":\"menor\",\"ci\":10002,\"nombre\":\"Maria Vargas\"}" &&
		m[2][2]->toString() == "{\"tipo\":\"adulto\",\"ci\":10003,\"nombre\":\"Pedro Rodriguez\"}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int test2()
{
	cout << "----test 2--" << endl;
	//Creamos la sala de cine(nombre, filas, columnas)
	SalaCine salaCine("Sala 1", 2, 2);
	//Creamos funciones en la sala(id,pelicula)
	salaCine.crearFuncion(1, "El Rey Leon");
	salaCine.crearFuncion(2, "Batman");
	salaCine.crearFuncion(3, "LEGO");
	cout << salaCine.toString() << endl;
	cout << "esperado:" << endl;
	cout << "{\"nombre\":\"Sala 1\",\"funciones\":[{\"id\":1,\"pelicula\":\"El Rey Leon\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{}}]},{\"id\":2,\"pelicula\":\"Batman\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{}}]},{\"id\":3,\"pelicula\":\"LEGO\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{}}]}]}" << endl;
	if (salaCine.toString() == "{\"nombre\":\"Sala 1\",\"funciones\":[{\"id\":1,\"pelicula\":\"El Rey Leon\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{}}]},{\"id\":2,\"pelicula\":\"Batman\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{}}]},{\"id\":3,\"pelicula\":\"LEGO\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{}}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int test3()
{
	cout << "----test 3--" << endl;
	//Creamos la sala de cine(nombre, filas, columnas)
	SalaCine salaCine("Sala 1", 3, 3);
	//Registramos clientes
	salaCine.registrar(new Adulto(10001, "Juan Perez"));
	salaCine.registrar(new Menor(10002, "Maria Vargas"));
	salaCine.registrar(new Adulto(10003, "Pedro Rodriguez"));
	//Creamos una funcion en la sala(id,pelicula)
	salaCine.crearFuncion(1, "El Rey Leon");
	//Agregamos clientes a la funcion en asientos determinados
	salaCine.registrarCliente(1, 0, 0, 10001);
	salaCine.registrarCliente(1, 1, 1, 10002);
	salaCine.registrarCliente(1, 2, 2, 10003);
	cout << salaCine.toString() << endl;
	cout << "esperado:" << "{\"nombre\":\"Sala 1\",\"funciones\":[{\"id\":1,\"pelicula\":\"El Rey Leon\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{\"tipo\":\"adulto\",\"ci\":10001,\"nombre\":\"Juan Perez\"}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":0,\"columna\":2, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{\"tipo\":\"menor\",\"ci\":10002,\"nombre\":\"Maria Vargas\"}},{\"fila\":1,\"columna\":2, \"persona\":{}},{\"fila\":2,\"columna\":0, \"persona\":{}},{\"fila\":2,\"columna\":1, \"persona\":{}},{\"fila\":2,\"columna\":2, \"persona\":{\"tipo\":\"adulto\",\"ci\":10003,\"nombre\":\"Pedro Rodriguez\"}}]}]}" << endl;
	if (salaCine.toString() == "{\"nombre\":\"Sala 1\",\"funciones\":[{\"id\":1,\"pelicula\":\"El Rey Leon\",\"sala\":[{\"fila\":0,\"columna\":0, \"persona\":{\"tipo\":\"adulto\",\"ci\":10001,\"nombre\":\"Juan Perez\"}},{\"fila\":0,\"columna\":1, \"persona\":{}},{\"fila\":0,\"columna\":2, \"persona\":{}},{\"fila\":1,\"columna\":0, \"persona\":{}},{\"fila\":1,\"columna\":1, \"persona\":{\"tipo\":\"menor\",\"ci\":10002,\"nombre\":\"Maria Vargas\"}},{\"fila\":1,\"columna\":2, \"persona\":{}},{\"fila\":2,\"columna\":0, \"persona\":{}},{\"fila\":2,\"columna\":1, \"persona\":{}},{\"fila\":2,\"columna\":2, \"persona\":{\"tipo\":\"adulto\",\"ci\":10003,\"nombre\":\"Pedro Rodriguez\"}}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 60;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = test1() + test2() + test3();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}