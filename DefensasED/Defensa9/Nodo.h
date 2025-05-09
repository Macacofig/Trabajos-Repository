#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define TAM 28
using namespace std;

template <class T>
class Nodo
{
private:
	bool fin;
	Nodo<T>* vec[TAM];
public:
	Nodo();
	~Nodo();
	bool Fin();
	Nodo<T>* getVec(int pos);
	void setfin(bool fin);
	void setVec(int pos, Nodo<T>* nodo);
};

template<class T>
Nodo<T>::Nodo()
{
	fin = false;
	for (int i = 0; i < TAM; i++)
	{
		vec[i] = NULL;
	}
}
template<class T>
Nodo<T>::~Nodo()
{

}
template<class T>
bool Nodo<T>::Fin() 
{
	return fin;
}

template<class T>
Nodo<T>* Nodo<T>::getVec(int pos)
{
	return vec[pos];
}

template<class T>
void Nodo<T>::setfin(bool fin)
{
	this->fin = fin;
}

template<class T>
void Nodo<T>::setVec(int pos, Nodo<T>* nodo)
{
	vec[pos] = nodo;
}


