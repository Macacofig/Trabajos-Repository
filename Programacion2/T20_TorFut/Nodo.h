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
	Nodo<T>* getSig();
	void setDato(T* dato);
	void crearNodo(T* dato);
};

template<class T>
inline Nodo<T>::Nodo(T* dato)
{
	this->dato = dato;
	sig = NULL;
}

template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline T* Nodo<T>::getDato()
{
	return dato;
}

template<class T>
inline Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}

template<class T>
inline void Nodo<T>::setDato(T* dato)
{
	this->dato = dato;
}

template<class T>
inline void Nodo<T>::crearNodo(T* dato)
{
	sig = new Nodo<T>(dato);
}
