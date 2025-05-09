#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Nodo
{
private:
	T dato;
	Nodo<T>* Right;
	Nodo<T>* Left;
public:
	Nodo();
	Nodo(T dato);//T* dato para cualquier clase
	~Nodo();
	T getDato();
	Nodo<T>*& getRRef();
	Nodo<T>*& getLRef();
    Nodo<T>* getRight();
	Nodo<T>* getLeft();
	void setRight(Nodo<T>* right);
	void setLeft(Nodo<T>* left);
	void setDato(T dato);//T* dato para cualquier clase
};

template<class T>
Nodo<T>::Nodo()
{
	Right = NULL;
	Left = NULL;
}

template<class T>
Nodo<T>::Nodo(T dato)
{
	Right = NULL;
	Left = NULL;
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
Nodo<T>*& Nodo<T>::getRRef()
{
	return Right;
}
template<class T>
inline Nodo<T>*& Nodo<T>::getLRef()
{
	return Left;
}
template<class T>
 Nodo<T>* Nodo<T>::getRight()
{
	return Right;
}
template<class T>
 Nodo<T>* Nodo<T>::getLeft()
{
	return Left;
}
template<class T>
 void Nodo<T>::setRight(Nodo<T>* right)
{
	 this->Right = right;
}
template<class T>
 void Nodo<T>::setLeft(Nodo<T>* left)
 {
	 this->Left = left;
 }
template<class T>
void Nodo<T>::setDato(T dato)
{
	this->dato = dato;
}