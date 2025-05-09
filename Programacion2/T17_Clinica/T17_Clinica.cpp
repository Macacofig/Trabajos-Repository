/*
Una clinica de animales domesticos desea llevar control de las atenciones que realiza a sus clientes.
Existen dos tipos de atenciones :
• médica, compuesto por código, descripcion, costo y medicamentos usados.
• peluquería, compuesto por código, descripcion, costo y la duración de la atención en minutos.
Las atenciones se reservan de dos maneras:
• Simple, en la cual se debe registrar: identificador, atención, cliente y mascota.
• Combo, en el cual se deben registrar: identificador, la primera atención, la segunda atención, cliente y mascota.
El sistema debe permitir al usuario realizar las siguientes tareas:
• Registrar clientes y mascotas y ordenarlas nombre.
• Registrar atenciones y mostrarlas ordenadas por código.
• Registrar reservas y mostrarlas ordenados por fecha.

*/
#include "SingletonClientes.h"
#include "Clinica.h"

//Creamos clinicaAnimales
Clinica clinicaAnimales;

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Esperado" << endl;
	cout << "[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}]"<<endl;
	// Registramos clientes(CI,nombre,fono)
	SingletonClientes::getInst().registrar(new Cliente(12345, "Pedro", 55555));
	SingletonClientes::getInst().registrar(new Cliente(12346, "Juan", 55556));
	SingletonClientes::getInst().registrar(new Cliente(12347, "Aldo", 55557));
	// Registramos mascotas(nombre,edad)
	SingletonClientes::getInst().buscar(12345)->getMascotas().registrar(new Mascota("Fido", 2));
	SingletonClientes::getInst().buscar(12345)->getMascotas().registrar(new Mascota("Balto", 3));
	SingletonClientes::getInst().buscar(12346)->getMascotas().registrar(new Mascota("Figaro", 3));
	SingletonClientes::getInst().buscar(12347)->getMascotas().registrar(new Mascota("Spike", 5));
	cout << "Obtenido" << endl;
	cout << SingletonClientes::getInst().toString() << endl;
	if (SingletonClientes::getInst().toString() == "[{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557,\"mascotas\":[{\"nombre\":\"Spike\",\"edad\":5}]},{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"mascotas\":[{\"nombre\":\"Figaro\",\"edad\":3}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"mascotas\":[{\"nombre\":\"Balto\",\"edad\":3},{\"nombre\":\"Fido\",\"edad\":2}]}]")
	{
		cout << "Resultado: correcto" << endl;
		return 30;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	cout << "Esperado" << endl;
	cout << "{\"atenciones\":[{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120},{\"tipo\":\"AtencionMedica\",\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"medicamentos\":\"Rabigan\"},{\"tipo\":\"AtencionMedica\",\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"medicamentos\":\"lombrix\"},{\"tipo\":\"AtencionPeluqueria\",\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"duracion\":180}],\"reservas\":[]}" << endl;
	//registramos atenciones medicas (codigo,descripcion,costo,medicamentos)
	clinicaAnimales.registrarAtencion(new AtencionMedica(2, "vacuna antirrabica", 100, "Rabigan"));
	clinicaAnimales.registrarAtencion(new AtencionMedica(3, "desparasitacion", 120, "lombrix"));
	//registramos atenciones en peluqueria (codigo,descripcion,costo,duracionEnMinutos)
	clinicaAnimales.registrarAtencion(new AtencionPeluqueria(1, "corte pelo", 75, 120));
	clinicaAnimales.registrarAtencion(new AtencionPeluqueria(4, "ducha y limpieza", 90, 180));
	cout << "Obtenido" << endl;
	cout << clinicaAnimales.toString() << endl;
	if (clinicaAnimales.toString() == "{\"atenciones\":[{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120},{\"tipo\":\"AtencionMedica\",\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"medicamentos\":\"Rabigan\"},{\"tipo\":\"AtencionMedica\",\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"medicamentos\":\"lombrix\"},{\"tipo\":\"AtencionPeluqueria\",\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"duracion\":180}],\"reservas\":[]}")
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
	cout << "Esperado" << endl;
	cout << "{\"atenciones\":[{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120},{\"tipo\":\"AtencionMedica\",\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"medicamentos\":\"Rabigan\"},{\"tipo\":\"AtencionMedica\",\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"medicamentos\":\"lombrix\"},{\"tipo\":\"AtencionPeluqueria\",\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"duracion\":180}],\"reservas\":[{\"ReservaSimple\":{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"mascota\":{\"nombre\":\"Balto\",\"edad\":3}},\"atencion\":{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120}},{\"ReservaMultiple\":{\"id\":3,\"cliente\":{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557},\"mascota\":{\"nombre\":\"Spike\",\"edad\":5}},\"atencion1\":{\"tipo\":\"AtencionPeluqueria\",\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"duracion\":180},\"atencion2\":{\"tipo\":\"AtencionMedica\",\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"medicamentos\":\"Rabigan\"}},{\"ReservaMultiple\":{\"id\":4,\"cliente\":{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556},\"mascota\":{\"nombre\":\"Figaro\",\"edad\":3}},\"atencion1\":{\"tipo\":\"AtencionMedica\",\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"medicamentos\":\"lombrix\"},\"atencion2\":{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120}}]}" << endl;
	//Registramos reserva simple(idReserva, codigoAtencion, ciCliente, string nombreMascota)
	clinicaAnimales.registrarReservaSimple(1, 1, 12345, "Balto");
	//Registramos reserva multiple(idReserva, codigoAtencion1, codigoAtencion2, ciCliente, nombreMascota)
	clinicaAnimales.registrarReservaMultiple(3, 4, 2, 12347, "Spike");
	clinicaAnimales.registrarReservaMultiple(4, 3, 1, 12346, "Figaro");
	cout << "Obtenido" << endl;
	cout << clinicaAnimales.toString() << endl;
	if (clinicaAnimales.toString() == "{\"atenciones\":[{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120},{\"tipo\":\"AtencionMedica\",\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"medicamentos\":\"Rabigan\"},{\"tipo\":\"AtencionMedica\",\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"medicamentos\":\"lombrix\"},{\"tipo\":\"AtencionPeluqueria\",\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"duracion\":180}],\"reservas\":[{\"ReservaSimple\":{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"mascota\":{\"nombre\":\"Balto\",\"edad\":3}},\"atencion\":{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120}},{\"ReservaMultiple\":{\"id\":3,\"cliente\":{\"ci\":12347,\"nombre\":\"Aldo\",\"fono\":55557},\"mascota\":{\"nombre\":\"Spike\",\"edad\":5}},\"atencion1\":{\"tipo\":\"AtencionPeluqueria\",\"codigo\":4,\"descripcion\":\"ducha y limpieza\",\"costo\":90,\"duracion\":180},\"atencion2\":{\"tipo\":\"AtencionMedica\",\"codigo\":2,\"descripcion\":\"vacuna antirrabica\",\"costo\":100,\"medicamentos\":\"Rabigan\"}},{\"ReservaMultiple\":{\"id\":4,\"cliente\":{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556},\"mascota\":{\"nombre\":\"Figaro\",\"edad\":3}},\"atencion1\":{\"tipo\":\"AtencionMedica\",\"codigo\":3,\"descripcion\":\"desparasitacion\",\"costo\":120,\"medicamentos\":\"lombrix\"},\"atencion2\":{\"tipo\":\"AtencionPeluqueria\",\"codigo\":1,\"descripcion\":\"corte pelo\",\"costo\":75,\"duracion\":120}}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 40;
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