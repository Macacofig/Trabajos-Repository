#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class Nodoh
{
private:
	bool existe;
	T dato;

public:
	Nodoh();
	Nodoh(T dato,bool existe);
	~Nodoh();
	bool Existe();
	T Dato();
	void setExiste(bool existe);
	void setDato(T dato);
};

template<class T>
Nodoh<T>::Nodoh()
{
	existe = false;
}

template<class T>
Nodoh<T>::Nodoh(T dato, bool existe)
{
	this->dato = dato;
	this->existe = existe; 
}
template<class T>
Nodoh<T>::~Nodoh()
{

}
template<class T>
bool Nodoh<T>::Existe()
{
	return existe;
}

template<class T>
T Nodoh<T>::Dato()
{
	return dato;
}

template<class T>
void Nodoh<T>::setDato(T dato)
{
	this->dato = dato; 
}

template<class T>
void Nodoh<T>::setExiste(bool existe)
{
	this->existe = existe; 
}




