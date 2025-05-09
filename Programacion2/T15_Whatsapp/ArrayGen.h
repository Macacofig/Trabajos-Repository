#pragma once
#include <iostream>
#include <string>
#include<sstream>
#define CD 10
using namespace std;
template <class T>
class ArrayGen
{
private:
	int ind;
	T** datos;
public:
	ArrayGen();
	~ArrayGen();
	void registrar(T* dato);
	string toJson(string(*tToJson)(T*));
	T* buscar(T* dato);
	void ordenar(bool (*cmp)(T*, T*));
};

template<class T>
ArrayGen<T>::ArrayGen()
{
	datos = new T * [CD];
	ind = 0;
}

template<class T>
ArrayGen<T>::~ArrayGen()
{
	delete[] datos;
}

template<class T>
void ArrayGen<T>::registrar(T* dato)
{
	if (ind < CD)
	{
		datos[ind] = dato;
		ind++;
	}
}

template<class T>
string ArrayGen<T>::toJson(string(*tToJson)(T*))
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << (*tToJson)(datos[i]);
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}

template<class T>
T* ArrayGen<T>::buscar(T* dato)
{
	for (int i = 0; i < ind; i++)
	{
		if ((*datos[i]) == dato)
			return datos[i];
	}
	return NULL;
}

template<class T>
void ArrayGen<T>::ordenar(bool(*cmp)(T*, T*))
{
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind-1; j++)
		{
			if ((*cmp)(datos[j], datos[j + 1]))
			{
				swap(datos[j], datos[j + 1]);
			}
		}
	}
}
