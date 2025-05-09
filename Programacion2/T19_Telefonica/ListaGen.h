#pragma once
#include "Nodo.h"
template <class T>
class ListaGen
{
private:
	Nodo<T>* primerNodo;
	int cont;
public:
	ListaGen();
	~ListaGen();
	void registrar(T* dato);
	int getCont();
	T* buscar(T* dato);
	string toJson(string(*Json)(T* dato));
};

template<class T>
inline ListaGen<T>::ListaGen()
{
	primerNodo = NULL;
	cont = 0;
}

template<class T>
inline ListaGen<T>::~ListaGen()
{
}

template<class T>
inline void ListaGen<T>::registrar(T* dato)
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
		tmp->CrearNodo(dato);
	}
	cont++;
}

template<class T>
inline int ListaGen<T>::getCont()
{
	return cont;
}

template<class T>
inline T* ListaGen<T>::buscar(T* dato)
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
inline string ListaGen<T>::toJson(string (*Json)(T*))
{
	stringstream ss; 
	ss << "[";
	Nodo<T>* tmp = primerNodo;
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
