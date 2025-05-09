#pragma once
#include "Lista8.h"
#include <math.h>
#define TAM 1217
template<class T>
class Hash
{
private:
	Lista8<T> vecWords[TAM];
public:
	Hash();
	~Hash();
	int HFunction(string word);
	int InsertWordH(string word);
	int Search(string word);
	int DeleteH(string word);
	void ShowH();
	void showh(int &cv,int &cM);
};

template<class T>
inline Hash<T>::Hash()
{
}

template<class T>
inline Hash<T>::~Hash()
{
}

template<class T>
int Hash<T>::HFunction(string word)
{
	int cant=0;
	int pos;
	for (int i = 0; i < word.size(); i++)
	{
		cant = cant + (word[i]) * (pow(2,(i)));
	}
	pos = abs(cant % TAM)*2;
	return pos;
}

template<class T>
int Hash<T>::InsertWordH(string word)
{
	int res;
	int pos = HFunction(word);
	int control;
	if (pos >= TAM)
	{
		res = 0;
	}
	else
	{
		control = Search(word);
		if (control != -1)
		{
			res = 0;
		}
		else
		{
			res = vecWords[pos].Insert_Last(word);
		}
	}
	return res;
}

template<class T>
inline int Hash<T>::Search(string word)
{
	int res;
	int pos = HFunction(word);
	int control = vecWords[pos].Search_DateNR(word);
	if (control == -1) 
	{
		res = -1; 
	}
	else
	{
		res = control;
	}
	return res;
}

template<class T>
int Hash<T>::DeleteH(string word)
{
	int res;
	int pos = HFunction(word);
	res = vecWords[pos].clear(word);
	return res;
}

template<class T>
void Hash<T>::ShowH()
{
	for (int i = 0; i < TAM; i++)
	{
		cout << "Posicion:" << i + 1 << endl;
		vecWords[i].Show();
	}
}

template<class T>
void Hash<T>::showh(int& cv, int& cM)
{
	int res;
	int controlv = 0;
	int controlM = -10;
	for (int i = 0; i < TAM; i++)
	{
		res =vecWords[i].show();
		if (res == -1)
		{
			controlv++;
		}
		else
		{
			if (controlM <= res)
			{
				controlM = res;
			}
		}
	}
	if (controlM == -10)
	{
		controlM = 0;
	}
	cv = controlv;
	cM = controlM;
}
