#pragma once

#include"Matriz.h"
#include"Heroe.h"
#include"Villano.h"
#include"Bloque.h"
#include"ExceptionMovBloque.h"
#include"ExceptionCasOcupada.h"


class Juego
{
private:
	Matriz<Objeto*> mapa;
public:
	Juego(int fil,int col);
	~Juego();

	void agregar(Objeto* o);
	string getMapa();
	void mover(int id, int x,int y);
};

