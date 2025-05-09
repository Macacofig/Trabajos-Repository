#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template <class T>
class Matriz
{
private:
	int filas;
	int columnas;
	T** m;
public:
	Matriz(int filas, int columnas);
	~Matriz();
	void registrar(T dato, int fila, int col);
	T* operator[](int fila);
	void inicializar();
	string toString(string(*Json)(T), string dato);
};

template<class T>
Matriz<T>::Matriz(int filas, int columnas)
{
	this->filas = filas;
	this->columnas = columnas;
	m = new T * [filas];
	for (int i = 0; i < filas; i++)
	{
		m[i] = new T[columnas];
	}
}

template<class T>
Matriz<T>::~Matriz()
{
	for (int i = 0; i < filas; i++)
	{
		delete m[i];
	}
	delete m;
}

template<class T>
void Matriz<T>::registrar(T dato, int fila, int col)
{
	m[fila][col] = dato;
}

template<class T>
T* Matriz<T>::operator[](int fila)
{
	return m[fila];
}

template<class T>
void Matriz<T>::inicializar()
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			m[i][j] = NULL;
		}
	}
}

template<class T>
inline string Matriz<T>::toString(string(*Json)(T), string dato)
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			ss << "{\"fila\":" << i << ",\"columna\":" << j << ", \"" << dato << "\":";
			if (m[i][j] != NULL)
				ss << (*Json)(m[i][j]);
			else
			{
				ss << "{}";
			}
			ss << "}";
			if (j < columnas - 1)
			{
				ss << ",";
			}
		}
		if (i < filas - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}


