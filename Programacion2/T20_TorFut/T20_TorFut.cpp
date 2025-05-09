/*
Implementar un sistema para el control de torneos de futbol,
debe permitir al usuario realizar las siguientes tareas:
� Registrar equipos y ordenarlos nombre.
� Registrar partidos entre dos equipos.
� Registrar Goles(minuto, equipo, jugador)
� Registrar Cambios(minuto, equipo, jugador que entra y jugador que sale)
*/

#include "Torneo.h"

Torneo torneo;

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Requerido" << endl;
	cout << "{\"equipos\":[{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]}]}" << endl;
	cout << "" << endl;
	string error = "";
	try {
		// Registramos equipo(nombre)
		torneo.getEquipos().registrar("Barcelona");
		// Registramos jugador(ci,nombre,fono) en equipo
		torneo.getEquipos().buscar("Barcelona")->nuevoJugador(12, "leo", 12351);
		torneo.getEquipos().buscar("Barcelona")->nuevoJugador(11, "rob", 12352);
		torneo.getEquipos().buscar("Barcelona")->nuevoJugador(13, "fabi", 12353);
		torneo.getEquipos().buscar("Barcelona")->nuevoJugador(14, "sebas", 12354);
		torneo.getEquipos().buscar("Barcelona")->nuevoJugador(15, "josh", 12355);
		// Registramos equipo(nombre)
		torneo.getEquipos().registrar("Real Madrid");
		// Registramos jugador(ci,nombre,fono) en equipo
		torneo.getEquipos().buscar("Real Madrid")->nuevoJugador(22, "juan", 12341);
		torneo.getEquipos().buscar("Real Madrid")->nuevoJugador(21, "jose", 12342);
		torneo.getEquipos().buscar("Real Madrid")->nuevoJugador(23, "pablo", 12343);
		torneo.getEquipos().buscar("Real Madrid")->nuevoJugador(24, "matias", 12344);
		torneo.getEquipos().buscar("Real Madrid")->nuevoJugador(25, "lucas", 12345);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = torneo.toString(); //getEquipos().toString()
	cout << "Obtenido" << endl;
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"equipos\":[{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]}]}")
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
	cout << "Requerido" << endl;
	cout << "{partidos:[{\"id\":1,\"local\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"visitante\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"eventos\":[]},{\"id\":2,\"local\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"visitante\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"eventos\":[]}]}" << endl;
	cout << "" << endl;
	string error;
	try {
		// Buscamos equipo
		Equipo* w = torneo.getEquipos().buscar("Barcelona");
		// Buscamos equipo
		Equipo* a = torneo.getEquipos().buscar("Real Madrid");
		// Registramos equipo(id,local,visitante)
//		torneo.getPartidos().registrar(1, w, a); 
		// Registramos equipo(id,local,visitante)
//		torneo.getPartidos().registrar(2, a, w);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = torneo.toString();//getPartidos().toString()
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{partidos:[{\"id\":1,\"local\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"visitante\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"eventos\":[]},{\"id\":2,\"local\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"visitante\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"eventos\":[]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
/*
int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	string error;
	try {
		// Buscamos equipo
		Equipo* w = torneo.getEquipos().buscar("Barcelona");
		// Buscamos equipo
		Equipo* b = torneo.getEquipos().buscar("Patos");
		// Registramos equipo(id,local,visitante)
		torneo.getPartidos().registrar(3, w, b);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = torneo.getPartidos().toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "Equipo Patos inexistente" && result == "{partidos:[{\"id\":1,\"local\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"visitante\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"eventos\":[]},{\"id\":2,\"local\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"visitante\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"eventos\":[]}]}")
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
	string error;
	try {
		// Registramos Gol(minuto,equipo,ciJugador)
		torneo.getPartidos().buscar(1)->gol(10, "Barcelona", 12);
		// Registramos Gol(minuto,equipo,ciJugador)
		torneo.getPartidos().buscar(1)->gol(12, "Real Madrid", 22);
		// Registramos Gol(minuto,equipo,ciJugador)
		torneo.getPartidos().buscar(1)->gol(14, "Barcelona", 13);
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = torneo.getPartidos().buscar(1)->toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"id\":1,\"local\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":12,\"nombre\":\"leo\",\"fono\":12351},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355}]},\"visitante\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"eventos\":[{\"tipo\":\"gol\",\"minuto\":10,\"equipo\":\"Barcelona\",\"jugador\":\"leo\"},{\"tipo\":\"gol\",\"minuto\":12,\"equipo\":\"Real Madrid\",\"jugador\":\"juan\"},{\"tipo\":\"gol\",\"minuto\":14,\"equipo\":\"Barcelona\",\"jugador\":\"fabi\"}]}")
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
	string error;
	try {
		// Registramos Cambio(minuto,equipo,ciJugadorQueSale,nuevoJugadorQueEntra)
		torneo.getPartidos().buscar(1)->cambio(15, "Barcelona", 12, new Jugador(1000, "cris", 5555));
	}
	catch (exception& e) {
		error = e.what();
	}
	string result = torneo.getPartidos().buscar(1)->toString();
	cout << result << endl;
	cout << error << endl;
	if (error == "" && result == "{\"id\":1,\"local\":{\"nombre\":\"Barcelona\",\"jugadores\":[{\"ci\":11,\"nombre\":\"rob\",\"fono\":12352},{\"ci\":13,\"nombre\":\"fabi\",\"fono\":12353},{\"ci\":14,\"nombre\":\"sebas\",\"fono\":12354},{\"ci\":15,\"nombre\":\"josh\",\"fono\":12355},{\"ci\":1000,\"nombre\":\"cris\",\"fono\":5555}]},\"visitante\":{\"nombre\":\"Real Madrid\",\"jugadores\":[{\"ci\":21,\"nombre\":\"jose\",\"fono\":12342},{\"ci\":22,\"nombre\":\"juan\",\"fono\":12341},{\"ci\":23,\"nombre\":\"pablo\",\"fono\":12343},{\"ci\":24,\"nombre\":\"matias\",\"fono\":12344},{\"ci\":25,\"nombre\":\"lucas\",\"fono\":12345}]},\"eventos\":[{\"tipo\":\"gol\",\"minuto\":10,\"equipo\":\"Barcelona\",\"jugador\":\"leo\"},{\"tipo\":\"gol\",\"minuto\":12,\"equipo\":\"Real Madrid\",\"jugador\":\"juan\"},{\"tipo\":\"gol\",\"minuto\":14,\"equipo\":\"Barcelona\",\"jugador\":\"fabi\"},{\"tipo\":\"cambio\",\"minuto\":15,\"equipo\":\"Barcelona\",\"entra\":\"cris\",\"sale\":\"leo\"}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
*/
int main()
{
	int nota = pregunta1();// + pregunta2() + pregunta3() + pregunta4() + pregunta5();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}