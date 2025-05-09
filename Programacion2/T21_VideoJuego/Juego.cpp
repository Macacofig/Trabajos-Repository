#include "Juego.h"

Juego::Juego(int fil, int col)
	:mapa(fil,col)
{
}

Juego::~Juego()
{
}

void Juego::agregar(Objeto* o)
{
	mapa[o->getX()][o->getY()] = o;
}

string Juego::getMapa()
{
	return mapa.toString(Objeto::toStatic);
}

void Juego::mover(int id, int x, int y)
{
	Objeto* o = new Objeto(id);
	Objeto* buscado=mapa.buscar(o);
	if (buscado != NULL)
	{
		if (buscado->getTipo() != "bloque")
		{
			if (mapa[x][y] == NULL)
			{
				mapa.eliminar(o);
				mapa[x][y] = buscado;
			}
			else
			{
				throw ExceptionCasOcupada();
			}
		}
		else
		{
			throw ExceptionMovBloque();
		}
	}
	else
	{
		cout << "objeto no encontrado" << endl;
	}
}
