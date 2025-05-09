#pragma once
#include "ModEmpleados.h"
#define CANT_MAX_EINSCRITOS 10
#define CANT_MAX_EINSTRUCTORES 10
class Sesion
{
private:
	int idSesion;
	string fecha;
	string hora;
	string lugar;
	ModEmpleados easistieron;
	ModEmpleados instructores;
public:
	Sesion(int idSesion, string fecha, string hora, string lugar);
	~Sesion();
	int getidSesion();
	string getfecha();
	string gethora();
	string getlugar();
	void mostrar();
	string toJson();

	ModEmpleados& geteasistieron();
	ModEmpleados& getinstructores();
};

