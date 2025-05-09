/*
Una veterinaria desea llevar control de las atenciones que realiza a sus clientes.
Las atenciones estan compuestas por: código, descripcion, costo y detalle.
Las atenciones se deben reservar registrando la siguiente informacion: identificador, atención, cliente y mascota.
El sistema debe permitir al usuario realizar las siguientes tareas:
• Registrar clientes y mascotas y ordenarlas nombre.
• Registrar atenciones y mostrarlas ordenadas por código.
• Registrar reservas.

*/
#include "Veterinaria.h"

//Creamos veterinaria
Veterinaria veterinaria;

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "{\"clientes\":[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}],\"atenciones\":[],\"reservas\":[]}"<<endl;
	// Registramos clientes(CI,nombre,fono)
	veterinaria.registrarCliente(new Cliente(12345, "Pedro", 55555));
	veterinaria.registrarCliente(new Cliente(12346, "Juan", 55556));
	veterinaria.registrarCliente(new Cliente(12347, "Aldo", 55557));
	// Registramos mascotas(CI cliente, Mascota)
	veterinaria.registrarMascota(12345, new Mascota("Fido", 2));
	veterinaria.registrarMascota(12345, new Mascota("Balto", 3));
	veterinaria.registrarMascota(12346, new Mascota("Figaro", 3));
	veterinaria.registrarMascota(12347, new Mascota("Spike", 5));
	cout << "Resultado" << endl;
	cout << veterinaria.toString() << endl;
	if (veterinaria.toString() == "{\"clientes\":[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}],\"atenciones\":[],\"reservas\":[]}")
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
	cout << "{\"clientes\":[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}],\"atenciones\":[{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"},{\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"detalle\":\"Rabigan\"},{\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"detalle\":\"lombrix\"},{\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"detalle\":\"duchado y secado\"}],\"reservas\":[]}" << endl;
	//registramos atenciones (codigo,descripcion,costo,detalle)
	veterinaria.registrarAtencion(new Atencion(2, "vacuna antirrabica", 100, "Rabigan"));
	veterinaria.registrarAtencion(new Atencion(3, "desparasitacion", 120, "lombrix"));
	veterinaria.registrarAtencion(new Atencion(1, "corte pelo", 75, "corto"));
	veterinaria.registrarAtencion(new Atencion(4, "ducha y limpieza", 90, "duchado y secado"));
	cout << "Resultado" << endl;
	cout << veterinaria.toString() << endl;
	if (veterinaria.toString() == "{\"clientes\":[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}],\"atenciones\":[{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"},{\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"detalle\":\"Rabigan\"},{\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"detalle\":\"lombrix\"},{\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"detalle\":\"duchado y secado\"}],\"reservas\":[]}")
	{
		cout << "Resultado: correcto" << endl;
		return 30;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout << "{\"clientes\":[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}],\"atenciones\":[{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"},{\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"detalle\":\"Rabigan\"},{\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"detalle\":\"lombrix\"},{\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"detalle\":\"duchado y secado\"}],\"reservas\":[{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"mascota\":{\"nombre\":\"Balto\",\"edad\":3},\"atencion\":{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"}},{\"id\":3,\"cliente\":{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557},\"mascota\":{\"nombre\":\"Spike\",\"edad\":5},\"atencion\":{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"}},{\"id\":4,\"cliente\":{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556},\"mascota\":{\"nombre\":\"Figaro\",\"edad\":3},\"atencion\":{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"}}]}" << endl;
	//Registramos reserva simple(idReserva, codigoAtencion, ciCliente, string nombreMascota)
	veterinaria.registrarReserva(1, 1, 12345, "Balto");
	veterinaria.registrarReserva(3, 1, 12347, "Spike");
	veterinaria.registrarReserva(4, 1, 12346, "Figaro");
	cout << "Resultado" << endl;
	cout << veterinaria.toString() << endl;
	if (veterinaria.toString() == "{\"clientes\":[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}],\"atenciones\":[{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"},{\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"detalle\":\"Rabigan\"},{\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"detalle\":\"lombrix\"},{\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"detalle\":\"duchado y secado\"}],\"reservas\":[{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"mascota\":{\"nombre\":\"Balto\",\"edad\":3},\"atencion\":{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"}},{\"id\":3,\"cliente\":{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557},\"mascota\":{\"nombre\":\"Spike\",\"edad\":5},\"atencion\":{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"}},{\"id\":4,\"cliente\":{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556},\"mascota\":{\"nombre\":\"Figaro\",\"edad\":3},\"atencion\":{\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"detalle\":\"corto\"}}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 50;
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