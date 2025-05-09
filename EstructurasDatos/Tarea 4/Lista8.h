#pragma once
#include "Nodo.h"
template <class T>
class Lista8
{
private:
	Nodo<T>* pri;
	Nodo<T>* ult;
public:
	Lista8();
	~Lista8();
	Nodo<T>* getpri();
	bool Insert_First(T el);
	bool Delete_First();
	bool Insert_Last(T el);
	bool Delete_Last();
	bool Delete_All();
	void Show();
	T Search_Pos(int pos);
	int Search_DateNR(T el);
	int Search_DateR(T el, Nodo<T>* aux, int pos);
	int ControlEqual(T el);
	int clear(string word);
};

template<class T>
Lista8<T>::Lista8()
{
	pri = NULL;
	ult = NULL;
}
template<class T>
Lista8<T>:: ~Lista8()
{
}
template<class T>
Nodo<T>* Lista8<T>::getpri()
{
	return pri;
}

template<class T>
bool Lista8<T>::Insert_First(T el)
{
	bool res = true;
	if (pri == NULL)
	{
		pri = new Nodo<T>(el);
		ult = pri;
	}
	else
	{
		if (ControlEqual(el) != 1)//extra verificacion
		{
			res = false;
		}
		else
		{
			Nodo<T>* aux = new Nodo<T>(el);
			aux->setSig(pri);
			pri->setAnt(aux);
			pri = aux;
		}
	}
	return res;
}
template<class T>
bool Lista8<T>::Delete_First()
{
	bool res = true;
	if (pri == NULL)
	{
		res = false;
	}
	else
	{
		if (pri == ult)
		{
			delete pri;
			pri = NULL;
			ult = NULL;
		}
		else
		{
			Nodo<T>* aux = pri->getSig();
			aux->setAnt(NULL);
			delete pri;
			pri = aux;
		}
	}
	return res;
}
template<class T>
void Lista8<T>::Show()
{
	if (pri != NULL)
	{
		if (pri == ult)
		{
			cout << pri->getDato();
			cout << endl;
		}
		else
		{
			Nodo<T>* aux = pri;
			while (aux != ult)
			{
				cout << aux->getDato() << "/";
				aux = aux->getSig();
			}
			cout << aux->getDato();
			cout << endl;
		}
	}
}
template<class T>
bool Lista8<T>::Insert_Last(T el)
{
	bool res = true;
	if (ult == NULL)
	{
		ult = new Nodo<T>(el);
		pri = ult;
	}
	else
	{
		if (ControlEqual(el) != 1)//extra verificacion
		{
			res = false;
		}
		else
		{
			Nodo<T>* aux = new Nodo<T>(el);
			aux->setAnt(ult);
			ult->setSig(aux);
			ult = aux;
		}
	}
	return res;
}
template<class T>
bool Lista8<T>::Delete_Last()
{
	bool res = true;
	if (ult == NULL)
	{
		res = false;
	}
	else
	{
		if (pri == ult)
		{
			delete ult;
			pri = NULL;
			ult = NULL;
		}
		else
		{
			Nodo<T>* aux = ult->getAnt();
			aux->setSig(NULL);
			delete ult;
			ult = aux;
		}
	}
	return res;
}
template<class T>
bool Lista8<T>::Delete_All()
{
	bool res = true;
	if (pri == NULL)
	{
		res = false;
	}
	else
	{
		if (pri == ult)
		{
			delete pri;
		}
		else
		{
			Nodo<T>* aux1 = pri;
			Nodo<T>* aux2;
			while (aux1->getSig() != ult)
			{
				aux2 = aux1->getSig();
				aux2->setAnt(NULL);
				delete aux1;
				aux1 = aux2;
			}
			//ult->setAnt(NULL);
			delete aux1;
			delete ult;
		}
		pri = NULL;
		ult = NULL;
	}
	return res;
}
template<class T>
T Lista8<T>::Search_Pos(int pos)
{
	T res;
	int i = 1;
	if (pri == NULL)
	{
		res = '0';
	}
	else
	{
		Nodo<T>* aux = pri;
		while (i < pos && aux != NULL)
		{
			i++;
			aux = aux->getSig();
		}
		if (aux == NULL)
		{
			res = '0';
		}
		else
		{
			res = aux->getDato();
		}
	}
	return res;
}
template<class T>
int Lista8<T>::Search_DateNR(T el)
{
	int res = -1;
	int i = 1;
	if (pri == NULL)
	{
		res = -1;
	}
	else
	{
		Nodo<T>* aux = pri;
		while (aux != NULL && res == -1)
		{
			if (aux->getDato() != el)
			{
				aux = aux->getSig();
				i++;
			}
			else
			{
				res = i;
			}
		}
	}
	return res;
}
template<class T>
int Lista8<T>::Search_DateR(T el, Nodo<T>* aux, int pos)
{
	int res;
	if (aux == NULL)
	{
		res = -1;
	}
	else
	{
		if (aux->getDato() == el)
		{
			res = pos;
		}
		else
		{
			res = Search_DateR(el, aux->getSig(), pos + 1);
		}
	}

	return res;
}
template<class T>
int Lista8<T>::ControlEqual(T el)
{
	int ctl = -1;
	int res;
	res = Search_DateNR(el);
	if (res == -1)
	{
		ctl = 1;
	}
	return ctl;
}

template<class T>
int Lista8<T>::clear(string word)
{
	int res = 1;
	if (pri == NULL)
	{
		res = 0;
	}
	else
	{
		Nodo<T>* aux = pri;
		while(aux->getDato() != word && aux !=NULL)
		{
			aux = aux->getSig();
		}
		if (aux == NULL)
		{
			res = 0;
		}
		else
		{
			if (aux == pri && aux == ult)
			{
				delete aux;
				pri = NULL;
				ult = NULL;
			}
			else
			{
				Nodo<T>* aux2;
				if (aux == pri)
				{
					aux2 = aux->getSig();
					aux2->setAnt(NULL);
					delete pri;
					pri = aux2;
				}
				else
				{
					if (aux == ult)
					{
						aux2 = aux->getAnt();
						aux2->setSig(NULL);
						delete ult;
						ult = aux2;
					}
					else
					{
						Nodo<T>* aux3;
						aux2 = aux->getAnt();
						aux3 = aux->getSig();
						aux2->setSig(aux3);
						aux3->setAnt(aux2);
						delete aux;
					}
				}
			}
		}
	}
	return res;
}
