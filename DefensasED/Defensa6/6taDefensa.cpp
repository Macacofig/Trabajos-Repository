#include "ArbolBinarioBusqueda.h"
#include <cstdlib>
#include <ctime>
int main()
{
	ArbolBinarioBusqueda<int> a;
	for (int i = 0; i < 1000000; i++)
	{
		a.insertar(rand() % 1000000,a.getRaizRef());
	}
	cout << a.contarNodo(a.getRaiz()) << endl;
	cout << a.Altura(a.getRaiz()) << endl;
}