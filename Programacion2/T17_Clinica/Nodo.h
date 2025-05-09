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
	T* getDato();
	void setDato(T* dato);
	Nodo<T>* getSig();
	void crearSigNodo(T* dato);
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
T* Nodo<T>::getDato()
{
	return dato;
}

template<class T>
void Nodo<T>::setDato(T* dato)
{
	this->dato = dato;
}

template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}

template<class T>
void Nodo<T>::crearSigNodo(T* dato)
{
	sig = new Nodo<T>(dato);
}


