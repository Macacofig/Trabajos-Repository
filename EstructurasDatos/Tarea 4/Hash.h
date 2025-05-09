#pragma once
#include "Lista8.h"
template<class T>
class Hash
{
private:
	Lista8<T> vecWords[173];
public:
	Hash();
	~Hash();
	int HFunction(string word);
	int InsertWordH(string word);
	int Search(string word);
	int DeleteH(string word);
	void ShowH();
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
	for (int i = 0; i < word.size(); i++)
	{
		cant = cant + (word[i]) * (i + 1);
	}
	return cant%173;
}

template<class T>
int Hash<T>::InsertWordH(string word)
{
	int res;
	int pos = HFunction(word);
	int control;
	if (pos >= 173)
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
	for (int i = 0; i < 173; i++)
	{
		//cout << "Posicion:" << i << endl;
		vecWords[i].Show();
	}
}
