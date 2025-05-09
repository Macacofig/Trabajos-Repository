#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Nodo
{
private:
	T dato;
	char color;
	Nodo<T>* Right;
	Nodo<T>* Left;
public:
	Nodo();
	Nodo(T dato);//T* dato para cualquier clase
	~Nodo();
	T getDato();
	char getColor();
	Nodo<T>*& getRRef();
	Nodo<T>*& getLRef();
	Nodo<T>* getRight();
	Nodo<T>* getLeft();
	void setRRef(Nodo<T>*& r);
	void setLRef(Nodo<T>*& l);
	void setRight(Nodo<T>* right);
	void setLeft(Nodo<T>* left);
	void setDato(T dato);//T* dato para cualquier clase
	void setColor(char color);
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
char Nodo<T>::getColor()
{
	return color;
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
void Nodo<T>::setRRef(Nodo<T>*& r)
{
	this->Right = r;
}
template<class T>
void Nodo<T>::setLRef(Nodo<T>*& l)
{
	this->Left = l;
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

template<class T>
void Nodo<T>::setColor(char color)
{
	this->color = color; 
}
