#pragma once
#include "Avion.h"
#include "ModAsientos.h"
#include "Persona.h"
class Vuelo
{
private:
	int numero;
	Avion* avion;
	ModAsientos asientos;
public:
	Vuelo(int numero, Avion* avion);
	~Vuelo();
	int getNumero();
	string toJson();


	void registrarPasajero(int fila, int columna, Persona* p);
	void intercambiarAsiento(Asiento* a1, Asiento* a2);
	void agregarAsientos();
};
