
#include "Punto.h"
#include "Linea.h"
#include "EGCompuesto.h"
#include <thread>

void ejemplo1()
{
	Punto p(1, 5, 5);
	p.dibujar();
	cout << endl;
	system("pause");
	p.borrar();
}
void ejemplo2()
{
	Linea l(1, 3, 3, 0, 3);
	l.dibujar();
	cout << endl;
	system("pause");
	l.borrar();
}
void ejemplo3()
{
	Punto* p = new Punto(1, 5, 5);
	Linea* l = new Linea(2, 3, 3, 0, 3);
	EGCompuesto egc(3);
	egc.agregar(p);
	egc.agregar(l);
	egc.dibujar();
	cout << endl;
	system("pause");
	egc.borrar();
}
void ejemplo4()
{
	Punto* p = new Punto(1, 5, 5);
	Linea* l = new Linea(2, 3, 3, 0, 3);
	EGCompuesto* egc1 = new EGCompuesto(3);
	egc1->agregar(p);
	EGCompuesto* egc2 = new EGCompuesto(4);
	egc2->agregar(l);
	egc1->agregar(egc2);

	egc1->dibujar();
	cout << endl;
	system("pause");
	egc1->borrar();
}
void ejemplo5(int tam)
{
	EGCompuesto* egc1 = new EGCompuesto(1);
	for (int i = 0; i < tam; i++)
	{
		egc1->agregar(new Linea(i, i + 1, i + 1, i % 2, i + 2));
	}
	egc1->dibujar();
	this_thread::sleep_for(chrono::milliseconds(1000));
	egc1->borrar();
	this_thread::sleep_for(chrono::milliseconds(1000));
}
void ejemplo6()
{
	for (int i = 0; i < 10; i++)
	{
		ejemplo5(i*i);
	}
}
void ejemplo7()
{
	ElementoGrafico* eg = new Punto(1, 4, 5);
	Punto* p = (Punto*)eg; //casting = IR A OTRO TIPO DE DATO, conversion explicita
	if (eg->getTipo() == "Punto")
	{

	}

}
void ejemplo8()
{

	if (elementos[i]->getTipo() == "Punto")
	{
		Punto* p = (Punto)elementos[i];
		p->setX(5);
		p->dibujar();
		system("pause");
		p->borrar();
	}
	if (elementos[i]->getTipo() == "Linea")
	{
		Linea* l = (Linea*)elementos[i];
		l->setOri(1);
		l->dibujar();
		system("pause");
		l->borrar();
	}
}
int main()
{
	ejemplo6();
}
