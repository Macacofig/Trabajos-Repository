#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Nodo
{
private:
	T dato;//T* dato para cualquier clase
    bool exist;
public:
	Nodo();
	Nodo(T dato);//T* dato para cualquier clase
	~Nodo();
	T getDato();
    bool getExist();
	void setExist(bool exists);
	void setDato(T dato);//T* dato para cualquier clase
};

template<class T>
inline Nodo<T>::Nodo()
{
	exist = false;
}

template<class T>
Nodo<T>::Nodo(T dato)
{
	exist = false;
	this->dato = dato;
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
bool Nodo<T>::getExist()
{
	return exist;
}
template<class T>
void Nodo<T>::setExist(bool exists)
{
	this->exist = exists;
}
template<class T>
void Nodo<T>::setDato(T dato)
{
	this->dato = dato;
}