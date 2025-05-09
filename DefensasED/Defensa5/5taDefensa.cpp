#include "ArbolBinario.h"


int main()
{
	ArbolBinario<int> a;
	a.InsertAleatory(4, 1);
	a.InsertAleatory(3, 1);
	a.InsertAleatory(2, 1);
	a.InsertAleatory(1, 1);
	a.InsertAleatory(6, 1);
	cout << endl;
	a.ShowPreOrder(1);
	cout << endl;
	cout << a.podaHojas(1);
	cout << endl;
	a.ShowPreOrder(1);
}