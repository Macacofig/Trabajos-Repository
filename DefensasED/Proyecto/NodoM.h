#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class NodoM
{
private:
	bool existe;
	T dato;

public:
	NodoM();
	NodoM(T dato,bool existe);
	~NodoM();
	bool Existe();
	T Dato();
	void setExiste(bool existe);
	void setDato(T dato);
};

template<class T>
NodoM<T>::NodoM()
{
	existe = false;
}

template<class T>
NodoM<T>::NodoM(T dato, bool existe)
{
	this->dato = dato;
	this->existe = existe; 
}
template<class T>
NodoM<T>::~NodoM()
{

}
template<class T>
bool NodoM<T>::Existe()
{
	return existe;
}

template<class T>
T NodoM<T>::Dato()
{
	return dato;
}

template<class T>
void NodoM<T>::setDato(T dato)
{
	this->dato = dato; 
}

template<class T>
void NodoM<T>::setExiste(bool existe)
{
	this->existe = existe; 
}




