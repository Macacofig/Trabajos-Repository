#pragma once
#include "Hash.h"
template<class T>
class HashSimple
{
private:
	Hash<T> vecHash[20];
public:
	HashSimple();
	~HashSimple();
	int  HSFunction(string word);
	int InsertWord(string word);
	int DeleteWord(string word);
	int SearchWord(T word);
	void Show();
	bool InsertArchivo(T word);
};

template<class T>
 HashSimple<T>::HashSimple()
{
}

template<class T>
 HashSimple<T>::~HashSimple()
{
}

 template<class T>
  int HashSimple<T>::HSFunction(string word)
 {
	 return word.size();
 }

template<class T>
 int HashSimple<T>::InsertWord(string word)
{
	int res;
	int pos = HSFunction(word) - 1;
	if (pos >= 20)
	{
		res = 0;
	}
	else
	{
		res = vecHash[pos].InsertWordH(word);
	}
	return res;
}

template<class T>
 int HashSimple<T>::DeleteWord(string word)
{
	int res = 1;
	int pos = HSFunction(word) - 1;
	if (pos >= 20)
	{
		res = 0;
	}
	else
	{
		res = vecHash[pos].DeleteH(word);
	}
	return res;
}

template<class T>
 int HashSimple<T>::SearchWord(T word)
{
	int res;
	int pos = HSFunction(word) - 1;
	int control = vecHash[pos].Search(word);
	if (control == 0)
	{
		res = 0;
	}
	else
	{
		res = control;
	}
	return res;
}

template<class T>
 void HashSimple<T>::Show()
{
	 for (int i = 0; i < 20; i++)
	 {
		 cout << "Posicion: " << i + 1 << endl;
		 vecHash[i].ShowH();
	 }
}

template<class T>
 bool HashSimple<T>::InsertArchivo(T word)
{
	bool res = true;
	string auxword;
	ifstream archivo;
	archivo.open(word);
	if (!archivo)
	{
		res = false;
	}
	else
	{
			while (archivo >> auxword)
			{
				InsertWord(auxword);
			}
	}
	archivo.close();
	return res;
}
