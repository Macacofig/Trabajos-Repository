#pragma once
#include <math.h>
#include "Nodo.h"
#define TAM 128
template <class T>

class Monticulo
{
private:
	Nodo<T>* vec[128];
	int last;
public:
	Monticulo();
	~Monticulo();
	void INSERTAR(T el);
	void Recuperar_D_U(int hoja);
	void Recuperar_U_D(int hoja);
	int ELIMINAR();
	string ELIMINARS();
	void MOSTRAR();
	void LEERARCHIVO(string nombre);
};

template<class T>
Monticulo<T>::Monticulo()
{
	last = 0;
	for (int i = 0; i < TAM; i++)
	{
		vec[i] = new Nodo<T>();
	}
}

template<class T>
Monticulo<T>::~Monticulo()
{
}

template<class T>
void Monticulo<T>::INSERTAR(T el)
{
	if (last == 0)
	{
		last = 1;
		vec[last]->setDato(el);
		vec[last]->setExiste(true);

	}
	else
	{
		last = last + 1;
		vec[last]->setDato(el);
		vec[last]->setExiste(true);
		Recuperar_D_U(last);
	}
}

template<class T>
void Monticulo<T>::Recuperar_D_U(int hoja)
{
	if (hoja / 2 > 0)
	{
		if (vec[hoja]->Dato() < vec[hoja / 2]->Dato())
		{
			swap(vec[hoja], vec[hoja / 2]);
			Recuperar_D_U(hoja / 2);
		}
	}
}

template<class T>
void Monticulo<T>::Recuperar_U_D(int hoja)
{
	if (vec[2 * hoja]->Existe() && vec[(2 * hoja) + 1]->Existe())
	{
		if (vec[2 * hoja]->Dato() < vec[(2 * hoja) + 1]->Dato())
		{
			if (vec[2 * hoja]->Dato() < vec[hoja]->Dato())
			{
				swap(vec[2 * hoja], vec[hoja]);
				Recuperar_U_D(2 * hoja);
			}
		}
		else
		{
			if (vec[(2 * hoja) + 1]->Dato() < vec[hoja]->Dato())
			{
				swap(vec[(2 * hoja) + 1], vec[hoja]);
				Recuperar_U_D((2 * hoja) + 1);
			}
		}
	}
	else
	{
		if (vec[2 * hoja]->Existe())
		{
			if (vec[2 * hoja]->Dato() < vec[hoja]->Dato())
			{
				swap(vec[2 * hoja], vec[hoja]);
			}
		}
	}
}

template<class T>
int Monticulo<T>::ELIMINAR()
{
	int res;
	if (last == 0)
	{
		res = -10000;
	}
	else
	{
		res = vec[1]->Dato();
		vec[1]->setDato(vec[last]->Dato());
		vec[last]->setExiste(false);
		last = last - 1;
		Recuperar_U_D(1);
	}
	return res;
}

template<class T>
string Monticulo<T>::ELIMINARS()
{
	string res;
	if (last == 0)
	{
		res = "Vacio";
	}
	else
	{
		res = vec[1]->Dato();
		vec[1]->setDato(vec[last]->Dato());
		vec[last]->setExiste(false);
		last = last - 1;
		Recuperar_U_D(1);
	}
	return res;
}

template<class T>
void Monticulo<T>::MOSTRAR()
{
	int fila = 0;
	int control = 1;
	if (last != 0)
	{
		for (int i = 1; i <= last; i++)
		{
			cout << vec[i]->Dato();
			if (control == pow(2, fila))
			{
				cout << " {***}" << endl;
				fila = fila + 1;
				control = 1;
			}
			else
			{
				cout << "/";
				control = control + 1;
			}
			
		}
	}
	cout << endl;
}

template<class T>
void Monticulo<T>::LEERARCHIVO(string nombre)
{
	fstream arch;
	arch.open(nombre);
	string linea;
	if (!arch) 
	{
		cout << "error" <<endl;
	}
	while (arch >> linea)
	{
		INSERTAR(linea);
	}
	arch.close();
}
