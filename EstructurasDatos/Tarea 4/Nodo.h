#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Nodo
{
private:
	T dato;//T* dato para cualquier clase
	Nodo<T>* sig;
	Nodo<T>* ant;
public:
	Nodo(T dato);//T* dato para cualquier clase
	~Nodo();
	T getDato();
	void setDato(T dato);//T* dato para cualquier clase
	Nodo<T>* getSig();
	Nodo<T>* getAnt();
	void setSig(Nodo<T>* nodo);
	void setAnt(Nodo<T>* nodo);
};

template<class T>
Nodo<T>::Nodo(T dato)
{
	this->dato = dato;
	sig = NULL;
	ant = NULL;
}
template<class T>
Nodo<T>::~Nodo()
{

}
template<class T>
T Nodo<T>::getDato() //T* dato para cualquier clase
{
	return dato;
}
template<class T>
void Nodo<T>::setDato(T dato)
{
	this->dato = dato;
}
template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}
template<class T>
Nodo<T>* Nodo<T>::getAnt()
{
	return ant;
}
template<class T>
void Nodo<T>::setSig(Nodo<T>* nodo)
{
	this->sig = nodo;
}
template<class T>
void Nodo<T>::setAnt(Nodo<T>* nodo)
{
	this->ant = nodo;
}