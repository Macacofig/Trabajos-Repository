#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template <class T>
class Nodo
{
private:
	T* dato;
	Nodo<T>* sig;
public:
	Nodo(T* dato);
	~Nodo();
	T* getdato();
	Nodo<T>* getsig();
	void sigNodo(T* dato);
};

template<class T>
Nodo<T>::Nodo(T* dato)
{
	this->dato = dato;
	sig = NULL;
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
T* Nodo<T>::getdato()
{
	return dato;
}

template<class T>
Nodo<T>* Nodo<T>::getsig()
{
	return sig;
}

template<class T>
void Nodo<T>::sigNodo(T* dato)
{
	sig = new Nodo<T>(dato);
}
