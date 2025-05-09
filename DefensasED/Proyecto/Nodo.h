#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
template <class T>
class Nodo
{
private:
	vector<T> vec;
public:
	Nodo();
	~Nodo();
	vector<T>& v();
	const vector<T>& v1() const ;
	//void eliminararista(T eliminado);
};

template <class T>
Nodo<T>::Nodo()
{
}

template <class T>
Nodo<T>::~Nodo()
{

}

template <class T>
vector<T>& Nodo<T>::v()
{
	return vec;
}

template<class T>
inline const vector<T>& Nodo<T>::v1() const
{
	return vec;
}
/*
template<class T>
void Nodo<T>::eliminararista(T eliminado)
{
	int ultimo = vec.size() - 1;
	for(int i=0;i< vec.size();i++)
	{
		if (vec[i] == eliminado)
		{
			swap(vec[i], vec[ultimo]);
			vec.pop_back();
			ultimo = vec.size() - 1;
		}
	}
}
*/