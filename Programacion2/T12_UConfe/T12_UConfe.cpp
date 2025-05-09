/*
* Una universidad desea una aplicaci�n para administrar las conferenciaes que realiza.
La aplicaci�n debe permitir al usuario:
� Registrar conferenciaes.
� Registrar participantes.
*/

#include "Universidad.h"
int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"numero\":1,\"fecha\":20220101,\"lugar\":\"Auditorio ucb\",\"instructores\":[{\"nombre\":\"Juan\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Jose\",\"carrera\":\"Sistemas\"},{\"nombre\":\"Maria\",\"carrera\":\"Sistemas\"}]}" << endl;
	//crear conferencia(numero de conferencia, fecha, lugar)
	Conferencia* conferencia = new ConferenciaPresencial(1, 20220101, "Auditorio ucb");
	//registramos docente en conferencia(nombre participante, especialidad)
	conferencia->registrar(new Docente("Juan", "Programacion"));
	//registramos estudiante en conferencia(nombre participante, carrera)
	conferencia->registrar(new Estudiante("Jose", "Sistemas"));
	conferencia->registrar(new Estudiante("Maria", "Sistemas"));
	cout << "Resultado obtenido:" << endl;
	cout << conferencia->toJson() << endl;
	if (conferencia->toJson() == "{\"numero\":1,\"fecha\":20220101,\"lugar\":\"Auditorio ucb\",\"instructores\":[{\"nombre\":\"Juan\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Jose\",\"carrera\":\"Sistemas\"},{\"nombre\":\"Maria\",\"carrera\":\"Sistemas\"}]}")
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
	cout << "Resultado esperado:" << endl;
	cout << "{\"numero\":1,\"fecha\":20220101,\"link\":\"http://meet.google.com?asfd-asdf\",\"instructores\":[{\"nombre\":\"Juan\",\"especialidad\":\"Programacion\"},{\"nombre\":\"Pedro\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Jose\",\"carrera\":\"Sistemas\"},{\"nombre\":\"Maria\",\"carrera\":\"Sistemas\"}]}" << endl;
	//crear conferencia(numero de conferencia, fecha, link)
	Conferencia* conferencia = new ConferenciaVirtual(1, 20220101, "http://meet.google.com?asfd-asdf");
	//registramos docente en conferencia(nombre participante, especialidad)
	conferencia->registrar(new Docente("Juan", "Programacion"));
	conferencia->registrar(new Docente("Pedro", "Programacion"));
	//registramos estudiante en conferencia(nombre participante, carrera)
	conferencia->registrar(new Estudiante("Jose", "Sistemas"));
	conferencia->registrar(new Estudiante("Maria", "Sistemas"));
	cout << "Resultado obtenido:" << endl;
	cout << conferencia->toJson() << endl;
	if (conferencia->toJson() == "{\"numero\":1,\"fecha\":20220101,\"link\":\"http://meet.google.com?asfd-asdf\",\"instructores\":[{\"nombre\":\"Juan\",\"especialidad\":\"Programacion\"},{\"nombre\":\"Pedro\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Jose\",\"carrera\":\"Sistemas\"},{\"nombre\":\"Maria\",\"carrera\":\"Sistemas\"}]}")
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
	cout << "Resultado esperado:" << endl;
	cout << "{\"nombre\":\"ucb\",\"direccion\":\"Av Eudoro Galindo\",\"conferencias\":[{\"numero\":1,\"fecha\":20220101,\"link\":\"http://meet.google.com?asfd-asdf\",\"instructores\":[{\"nombre\":\"Juan\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Maria\",\"carrera\":\"Sistemas\"}]},{\"numero\":2,\"fecha\":20220101,\"lugar\":\"Auditorio ucb\",\"instructores\":[{\"nombre\":\"Jose\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Pedro\",\"carrera\":\"Sistemas\"}]}]}" << endl;
	//crear universidad(nombre, direccion)
	Universidad universidad("ucb", "Av Eudoro Galindo");
	//registrar conferencia(numero conferencia)
	universidad.registrarConferenciaVirtual(1, 20220101, "http://meet.google.com?asfd-asdf");
	universidad.registrarConferenciaPresencial(2, 20220101, "Auditorio ucb");
	//registrar participante en conferencia
	universidad.registrarParticipanteEnConferencia(1, new Docente("Juan", "Programacion"));
	universidad.registrarParticipanteEnConferencia(2, new Docente("Jose", "Programacion"));
	universidad.registrarParticipanteEnConferencia(1, new Estudiante("Maria", "Sistemas"));
	universidad.registrarParticipanteEnConferencia(2, new Estudiante("Pedro", "Sistemas"));
	cout << "Resultado obtenido:" << endl;
	cout << universidad.toJson() << endl;
	if (universidad.toJson() == "{\"nombre\":\"ucb\",\"direccion\":\"Av Eudoro Galindo\",\"conferencias\":[{\"numero\":1,\"fecha\":20220101,\"link\":\"http://meet.google.com?asfd-asdf\",\"instructores\":[{\"nombre\":\"Juan\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Maria\",\"carrera\":\"Sistemas\"}]},{\"numero\":2,\"fecha\":20220101,\"lugar\":\"Auditorio ucb\",\"instructores\":[{\"nombre\":\"Jose\",\"especialidad\":\"Programacion\"}],\"participantes\":[{\"nombre\":\"Pedro\",\"carrera\":\"Sistemas\"}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 40;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	ModPersonas personas;
	personas.registrar(new Docente("Juan", "x"));
	personas << new Docente("juan", "x");
	cout << personas[0]->toJson() << endl;

	Docente d1("juan", "y");
	Estudiante e1("juan", "sistemas");

	if (d1 == e1)
	{
		cout << "son la misma personas" << endl;
	}
/*
	int nota = pregunta1() + pregunta2() + pregunta3();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
    cout << "====================" << endl;
	system("pause");
*/
	return 0;
}