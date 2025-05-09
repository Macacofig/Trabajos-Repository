#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

template <class T>
class Nodo
{
private:
	bool marca;
	int padre;
	vector<T> aristas;
public:
	Nodo(int padre, bool marca);
	~Nodo();
	bool Marca();
	int Padre();
	vector<T>& VecAristas();
	void sPadre(int padre);
	void sMarca( bool marca);
};

template<class T>
Nodo<T>::Nodo(int padre,bool marca)
{
	this->padre = padre;
	this->marca = marca;
}
template<class T>
Nodo<T>::~Nodo()
{

}

template<class T>
bool Nodo<T>::Marca()
{
	return marca;
}

template<class T>
int Nodo<T>::Padre()
{
	return padre;
}

template<class T>
vector<T>& Nodo<T>::VecAristas()
{
	return aristas;
}

template<class T>
void Nodo<T>::sPadre(int padre)
{
	this->padre=padre;
}

template<class T>
void Nodo<T>::sMarca(bool marca)
{
	this->marca = marca;
}

