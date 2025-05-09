#pragma once
#include "ModExposiciones.h"
class Museo
{
private:
	string nombre;
	string direccion;
	ModExposiciones exposiciones;
public:
	Museo(string nombre, string direccion);
	~Museo();
	ModExposiciones& getExposiciones();
	void registrarExposicion(int numero);
	void registrarArtistaEnExposicion(int numero, Pintor* pintor);
	void registrarArtistaEnExposicion(int numero, Escultor* escultor);
	void registrarObraEnExposicion(int numero, string nombre, Escultura* escultura);
	void registrarObraEnExposicion(int numero, string nombre, Pintura* pintura);
	string toJson();


};

