#pragma once
#include "Nodo.h"
#include "Indeception.h"
template <class T>
class ListaGen
{
private:
	Nodo<T>* primerNodo;
public:
	ListaGen();
	~ListaGen();
	void registrar(string dat);
	void reggistrar(T* dato);
//	void registrar(int i,U dato1,U dato2);
	T* busccar(T* dato);
	T* buscar(string dat);
	string toString(string (*Json)(T*));
	void ordenar(bool(*cmp)(T*, T*));
};

template<class T>
inline ListaGen<T>::ListaGen()
{
	primerNodo = NULL;
}

template<class T>
inline ListaGen<T>::~ListaGen()
{
}

template<class T>
inline void ListaGen<T>::registrar(string dat)
{
	if (primerNodo == NULL)
	{
		primerNodo = new Nodo<T>(new T(dat));
	}
	else
	{
		Nodo<T>* tmp = primerNodo;
		while (tmp->getSig() != NULL)
		{
			tmp = tmp->getSig();
		}
		tmp->crearNodo(new T(dat));
	}
}

template<class T>
inline void ListaGen<T>::reggistrar(T* dato)
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
		tmp->crearNodo(dato);
	}
}

template<class T>
inline T* ListaGen<T>::busccar(T* dato)
{
	Nodo<T>* tmp = primerNodo;
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == dato)
		{
			return tmp->getDato();
		}
		else
		{
			tmp = tmp->getSig();
		}
	}
	return NULL;
}

template<class T>
inline T* ListaGen<T>::buscar(string dat)
{
	Nodo<T>* tmp = primerNodo;
	T t(dat);
	while (tmp != NULL)
	{
		if (*(tmp->getDato()) == &t)
		{
			return tmp->getDato();
		}
		else
		{
			tmp = tmp->getSig();
		}
	}
	throw Indeception(dat);
	return NULL;
}

template<class T>
inline string ListaGen<T>::toString(string (*Json)(T*))
{
	stringstream ss;
	Nodo<T>* tmp = primerNodo;
	ss << "[";
	while (tmp != NULL)
	{
		ss << (*Json)(tmp->getDato());
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
inline void ListaGen<T>::ordenar(bool(*cmp)(T*, T*))
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
