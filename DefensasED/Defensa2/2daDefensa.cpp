#include <iostream>
using namespace std;

template <class T>
class Nodo
{
private:
	T dato;//T* dato para cualquier clase
	Nodo<T>* sig;
	Nodo<T>* ant;
public:
	Nodo(T dato);//T* dato para cualquier clase
	~Nodo();
	T getDato();
	void setDato(T dato);//T* dato para cualquier clase
	Nodo<T>* getSig();
	Nodo<T>* getAnt();
	void setSig(Nodo<T>* nodo);
	void setAnt(Nodo<T>* nodo);
};

template<class T>
Nodo<T>::Nodo(T dato)
{
	this->dato = dato;
	sig = NULL;
	ant = NULL;
}
template<class T>
Nodo<T>::~Nodo()
{

}
template<class T>
T Nodo<T>::getDato() //T* dato para cualquier clase
{
	return dato;
}
template<class T>
void Nodo<T>::setDato(T dato)
{
	this->dato = dato;
}
template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}
template<class T>
Nodo<T>* Nodo<T>::getAnt()
{
	return ant;
}
template<class T>
void Nodo<T>::setSig(Nodo<T>* nodo)
{
	this->sig = nodo;
}
template<class T>
void Nodo<T>::setAnt(Nodo<T>* nodo)
{
	this->ant = nodo;
}
/****************************************** */
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
	Nodo<T>* getult();
	void setpri(Nodo<T>* npri);
	void setult(Nodo<T>* nult);
	bool Insert_First(T el);
	bool Delete_First();
	bool Insert_Last(T el);
	bool Delete_Last();
	bool Delete_All();
	void Show();
	T Search_Pos(int pos);
	int Search_DateNR(T el);
	int Search_DateR(T el, Nodo<T>* aux, int pos);
	Lista8<T> unir(Lista8<T> lcon);
	Lista8<T> unir1(Lista8<T> lcon);
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
Nodo<T>* Lista8<T>::getult()
{
	return ult;
}
template<class T>
void Lista8<T>::setpri(Nodo<T>* npri)
{
	this->pri = npri;
}
template<class T>
void Lista8<T>::setult(Nodo<T>* nult)
{
	this->ult = nult;
}
template<class T>
bool Lista8<T>::Insert_First(T el)
{
	if (pri == NULL)
	{
		pri = new Nodo<T>(el);
		ult = pri;
	}
	else
	{
		Nodo<T>* aux = new Nodo<T>(el);
		aux->setSig(pri);
		pri->setAnt(aux);
		pri = aux;
	}
	return true;
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
template<class T>
bool Lista8<T>::Insert_Last(T el)
{
	if (ult == NULL)
	{
		ult = new Nodo<T>(el);
		pri = ult;
	}
	else
	{
		Nodo<T>* aux = new Nodo<T>(el);
		aux->setAnt(ult);
		ult->setSig(aux);
		ult = aux;
	}
	return true;
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
Lista8<T> Lista8<T>::unir1(Lista8<T> lcon)
{
	Lista8<T> laux;
	laux.setpri(pri);
	laux.setult(ult);
	if (lcon.getpri() != NULL)
	{
		Nodo<T>* aux = lcon.getpri();
		while (aux != NULL)
		{
			laux.Insert_Last(aux->getDato());
			aux = aux->getSig();
		}
	}
	return laux;
}

template<class T>
Lista8<T> Lista8<T>::unir(Lista8<T> lcon)
{
	Lista8<T> laux;
	Nodo<T>* pauxL1 = pri;
	Nodo<T>* pauxL2 = lcon.getpri();
	if (pauxL1 != NULL)
	{
		while (pauxL1 != NULL)
		{
			laux.Insert_Last(pauxL1->getDato());
			pauxL1 = pauxL1->getSig();
		}
	}
	if (pauxL2 != NULL)
	{
		while (pauxL2 != NULL)
		{
			laux.Insert_Last(pauxL2->getDato());
			pauxL2 = pauxL2->getSig();
		}
	}
	return laux;
}


/************************************* */

int main()
{
	/*
	Lista8<char> l1,l2,l3,l4;
	l1.Insert_Last('a');
	l1.Insert_Last('b');
	l1.Insert_Last('c');
	l1.Insert_Last('d');
	l2.Insert_Last('x');
	l2.Insert_Last('y');
	l3 = l1.unir(l2);
	l1.Show();
	l2.Show();
	l3.Show();
	//l4 = l1.unir1(l2);
	//l4.Show();
	*/
	Lista8<char> l1;
	char g;
	for (int i = 1; i <= 1000000; i++)
	{
		l1.Insert_Last('0');
	}
	cout << endl;
	cin >> g;
	cout << l1.Search_DateNR(g)<<endl;
	return 0;
}