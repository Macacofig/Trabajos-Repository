#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class Nodo
{
private:
	bool existe;
	T dato;

public:
	Nodo();
	Nodo(T dato,bool existe);
	~Nodo();
	bool Existe();
	T Dato();
	void setExiste(bool existe);
	void setDato(T dato);
};

template<class T>
Nodo<T>::Nodo()
{
	existe = false;
}

template<class T>
Nodo<T>::Nodo(T dato, bool existe)
{
	this->dato = dato;
	this->existe = existe; 
}
template<class T>
Nodo<T>::~Nodo()
{

}
template<class T>
bool Nodo<T>::Existe() 
{
	return existe;
}

template<class T>
T Nodo<T>::Dato()
{
	return dato;
}

template<class T>
void Nodo<T>::setDato(T dato)
{
	this->dato = dato; 
}

template<class T>
void Nodo<T>::setExiste(bool existe)
{
	this->existe = existe; 
}




