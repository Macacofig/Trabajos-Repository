#pragma once
#include "IndException.h"
#define CM 10

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
	string toJson(string (*tToJson)(T*));
	void ordenar(bool (*cmp)(T*, T*));
	T* buscar(T* dato);
	T* operator[](int pos);
};
// Se borra el cpp, y los metodos se incluyen debajo de las declaraciones

template<class T>
ArrayGen<T>::ArrayGen()
{
	ind = 0;
	datos = new T * [CM];
}

template<class T>
ArrayGen<T>::~ArrayGen()
{
	delete[] datos;
}

template<class T>
void ArrayGen<T>::registrar(T* dato)
{
	if (ind < CM)
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
void ArrayGen<T>::ordenar(bool (*cmp)(T*,T*))
{
	for (int i = 0; i < ind; i++)
	{
		for (int j = 0; j < ind; j++)
		{
			if ((*cmp)(datos[j],datos[j + 1]))
			{
				swap(datos[j], datos[j + 1]);
			}
		}
	}
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
inline T* ArrayGen<T>::operator[](int pos)
{
	if (pos >= CM)
		throw string("Fuera de limite");
	if (pos >= ind)
		throw exception("No existe objeto en pos");
	if (pos < 0)
		throw IndException(pos);

	return datos[pos];
}
