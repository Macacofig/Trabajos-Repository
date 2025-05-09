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
	T* buscar(T* dato);
	string toString(string(*Json)(T*));

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
		while (tmp->getsig() != NULL)
		{
			tmp = tmp->getsig();
		}
		tmp->sigNodo(dato);
	}
}

template<class T>
T* ListaGen<T>::buscar(T* dato)
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (*(tmp->getdato()) == dato)
		{
			return tmp->getdato();
		}
		tmp = tmp->getsig();
	}
	return NULL;
}

template<class T>
string ListaGen<T>::toString(string(*Json)(T*))
{
	stringstream ss;
	Nodo<T>* tmp = primerNodo;
	ss << "[";
	while (tmp != NULL)
	{
		ss << (*Json)(tmp->getdato());
		if (tmp->getsig() != NULL)
		{
			ss << ",";
		}
		tmp = tmp->getsig();
	}
	ss << "]";
	return ss.str();
}
