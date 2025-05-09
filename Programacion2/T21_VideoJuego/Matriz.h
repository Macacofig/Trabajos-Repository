#pragma once

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template<class T>
class Matriz
{
private:
	T** datos;
	int fil;
	int col;
public:
	Matriz(int fil, int col);
	void reservar();
	~Matriz();

	T buscar(T buscado);
	void eliminar(T eliminado);

	T* operator[](int pos);
	string toString(string(*toStatic)(T));
};

template<class T>
 Matriz<T>::Matriz(int fil, int col)
{
	this->fil = fil;
	this->col = col;
	datos = new T*[fil];
	for (int i = 0; i < fil; i++)
	{
		datos[i] = new T[col];
	}
	reservar();
}

template<class T>
 void Matriz<T>::reservar()
{
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			datos[i][j] = NULL;
		}
	}
}

template<class T>
 Matriz<T>::~Matriz()
{
}

 template<class T>
  T Matriz<T>::buscar(T buscado)
 {
	 for (int i = 0; i < fil; i++)
	 {
		for (int j = 0; j < col; j++)
		{
			if (datos[i][j] != NULL)
			{
				if (*buscado == datos[i][j])
					return datos[i][j];
			}
		}
	 }
	 return NULL;
 }

  template<class T>
   void Matriz<T>::eliminar(T eliminado)
  {
	  for (int i = 0; i < fil; i++)
	  {
		  for (int j = 0; j < col; j++)
		  {
			  if (datos[i][j] != NULL)
			  {
				  if (*eliminado == datos[i][j])
					  datos[i][j]=NULL;
			  }
		  }
	  }
  }

template<class T>
 T* Matriz<T>::operator[](int pos)
{
	return datos[pos];
}

template<class T>
 string Matriz<T>::toString(string(*toStatic)(T))
{
	stringstream ss;
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(datos[i][j]!=NULL)
				ss << (*toStatic)(datos[i][j]);
			else
			{
				ss << "{0}";
			}
		}
		ss << "\n";
	}
	return ss.str();
}
