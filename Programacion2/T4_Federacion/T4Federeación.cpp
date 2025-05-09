#include "Federacion.h"

int main()
{
	Federacion fed("FED");
	fed.getjugadores().registrarju(new Jugador(1, "lucas", "hombre"));
	fed.getjugadores().registrarju(new Jugador(2, "Juan", "hombre"));
	fed.getjugadores().registrarju(new Jugador(3, "Marcos", "hombre"));
	fed.getjugadores().registrarju(new Jugador(4, "Luciano", "hombre"));
	fed.getequipos().registrareq(new Equipo(123, "Peques"));
	fed.getequipos().registrareq(new Equipo(121, "Pepes"));
	fed.getcampeonatos().registrar(new Campeonato("Mundial", 11, "14-12-2020"));
	fed.mostrar();
}

/*
	ss << "\"EquipoLocal\":" << local->toJson();
	ss << "\"EquipoVisitante\":" << visitante->toJson();
*/
