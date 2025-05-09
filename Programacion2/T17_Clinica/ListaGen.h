#pragma once
#include "Nodo.h"
template <class T>
class ListaGen
{
private:
	Nodo<T>* primerNodo;
public:
	ListaGen();
	~ListaGen();
	void registrar(T* dato);
	string toJson(string (*ToJSon)(T*));
	T* buscar(T* dato);
	void ordenar(bool (*cmp)(T*, T*));
};

template<class T>
ListaGen<T>::ListaGen()
{
	primerNodo = NULL;	
}

template<class T>
ListaGen<T>::~ListaGen()
{
}

template<class T>
void ListaGen<T>::registrar(T* dato)
{
	if (primerNodo == NULL)
	{
		primerNodo = new Nodo<T>(dato);
	}
	else
	{
		Nodo<T>* tmp = primerNodo;
		while (tmp->getSig() != NULL)
		{
			tmp = tmp->getSig();
		}
		tmp->crearSigNodo(dato);
	}
}

template<class T>
string ListaGen<T>::toJson(string(*ToJson)(T*))
{
	stringstream ss;
	ss << "[";
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		ss << (*ToJson)(tmp->getDato());
		if (tmp->getSig() != NULL)
		{
			ss << ",";
		}
		tmp = tmp->getSig();
	}
	ss << "]";
	return ss.str();
}

template<class T>
T* ListaGen<T>::buscar(T* dato)
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == dato)
			return tmp->getDato();
		tmp = tmp->getSig();
	}
	return NULL;
}

template<class T>
void ListaGen<T>::ordenar(bool(*cmp)(T*, T*))
{
	Nodo<T>* tmp = primerNodo;
	Nodo<T>* tmp2;
	while (tmp != NULL)
	{
		tmp2 = tmp->getSig();
		while (tmp2 != NULL)
		{
			if ((*cmp)(tmp->getDato(), tmp2->getDato()))
			{
				T* aux = tmp->getDato();
				tmp->setDato(tmp2->getDato());
				tmp2->setDato(aux);
			}
			tmp2 = tmp2->getSig();
		}
		tmp = tmp->getSig();
	}
}
