#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <typeinfo>

/*******************************************/
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
/*******************************************/
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
/****************************************************************************************/
template<class T,class Y>
class NodoP
{
private:
	NodoP<T, Y>* sig;
	NodoP<T, Y>* ant;
	T Criterio;
	Lista8<Y>* list;

public:
	NodoP();
	~NodoP();
	T getCriterio();
	Lista8<Y>* getlist();
	NodoP<T,Y>* getsig();
	NodoP<T,Y>* getant();
	void setCrit(int crit);
	void setsig(NodoP<T, Y>* sig);
	void setant(NodoP<T, Y>* ant);
};

template<class T,class Y>
NodoP<T, Y> ::NodoP()
{
	sig = NULL;
	ant = NULL;
	list = new Lista8<Y>();
}
template<class T,class Y>
NodoP<T, Y> ::~NodoP()
{
}

template<class T, class Y>
T NodoP<T, Y>::getCriterio()
{
	return Criterio;
}

template<class T, class Y>
Lista8<Y>* NodoP<T, Y>::getlist()
{
	return list;
}

template<class T, class Y>
NodoP<T, Y>* NodoP<T, Y>::getsig()
{
	return sig;
}

template<class T, class Y>
NodoP<T, Y>* NodoP<T, Y>::getant()
{
	return ant;
}
template<class T, class Y>
void NodoP<T, Y>::setCrit(int crit)
{
	this->Criterio = crit;
}
template<class T, class Y>
void NodoP<T, Y>::setsig(NodoP<T, Y>* sig)
{
	this->sig = sig;
}
template<class T, class Y>
void NodoP<T, Y>::setant(NodoP<T, Y>* ant)
{
	this->ant = ant;
}
/**********************************************************************************************/
template <class T,class Y>
class ListaListas
{
private:
	NodoP<T, Y>* pri;
	NodoP<T, Y>* ult;
public:
	ListaListas();
	~ListaListas();
	NodoP<T, Y>* getpri();
	NodoP<T, Y>* getult();
	bool InsertarFirst(Y el);
	bool DelletSubList(T criterio);
	void show();
	string SearchElemR(string el, NodoP<T,Y>* cabeza);
	bool SaveArchivo(string arc);
};
template<class T, class Y>
ListaListas<T, Y>::ListaListas()
{
	pri = NULL;
	ult = NULL;
}
template<class T, class Y>
ListaListas<T, Y>::~ListaListas()
{
}
template<class T, class Y>
NodoP<T, Y>* ListaListas<T, Y>::getpri()
{
	return pri;
}
template<class T, class Y>
NodoP<T, Y>* ListaListas<T, Y>::getult()
{
	return ult;
}
template<class T, class Y>
bool ListaListas<T, Y>::InsertarFirst(Y el)
{
	if (pri == NULL)
	{
		pri = new NodoP<T, Y>();
		pri->setCrit(el.size());
		pri->getlist()->Insert_Last(el);
		ult = pri;
	}
	else
	{
		NodoP<T,Y>* aux = pri;
		while (el.size() != aux->getCriterio() && aux != ult)
		{
			aux = aux->getsig();
		}
		if (el.size() == aux->getCriterio())
		{
			aux->getlist()->Insert_Last(el);
		}
		else
		{
			NodoP<T, Y>* newpri= new NodoP<T, Y>();
			newpri->setCrit(el.size()); 
			newpri->setsig(pri); 
			pri->setant(newpri);
			pri = newpri;
			pri->getlist()->Insert_Last(el);
		}
	}
	return true;
}
template<class T, class Y>
bool ListaListas<T, Y>::DelletSubList(T criterio)
{
	bool res = true;
	if (pri == NULL)
	{
		res = false;
	}
	else
	{
		NodoP<T, Y>* aux = pri;
		while (aux->getCriterio() != criterio && aux != NULL)
		{
			aux = aux->getsig();
		}
		if (aux == NULL)
		{
			res = false;
		}
		else
		{
			if (aux == pri && aux == ult)
			{
				aux->getlist()->Delete_All();
				delete aux;
				delete pri;
				delete ult;
			}
			else
			{
				if (aux == pri)
				{
					NodoP<T, Y>* aux2 = aux->getsig();
					aux2->setant(NULL);
					pri = aux2;
				}
				else
				{
					if (aux == ult)
					{
						NodoP<T, Y>* aux2 = aux->getant();
						aux2->setsig(NULL);
						ult = aux2;
					}
					else
					{
						NodoP<T, Y>* aux2 = aux->getant();
						NodoP<T, Y>* aux3 = aux->getsig();
						aux2->setsig(aux3);
						aux3->setant(aux2);
					}
				}
				aux->getlist()->Delete_All();
				delete aux;
			}		
		}
	}
	return res;
}

template<class T, class Y>
void ListaListas<T, Y>::show()
{
	if (pri != NULL)
	{
		if (pri == ult)
		{
			//cout << pri->getCriterio() << ": ";
			pri->getlist()->Show();
		}
		else
		{
			NodoP<T, Y>* aux = pri;
			while (aux != ult)
			{
				//cout << aux->getCriterio() << ": ";
				aux->getlist()->Show();
				aux = aux->getsig();
			}
			//cout << aux->getCriterio() << ": ";
			aux->getlist()->Show();
		}
	}
}

template<class T, class Y>
string ListaListas<T, Y>::SearchElemR(string el,NodoP<T,Y>* aux)
{
	string res;
	int num;
	if (pri == NULL)
	{
		res = "-1";
	}
	else
	{
		if (aux->getCriterio() == el.size()) 
		{
			num = aux->getlist()->Search_DateNR(el); 
			res = to_string(num);
		}
		else
		{
			res = SearchElemR(el, aux->getsig());
		}
	}
	return res;
}

template<class T, class Y>
bool ListaListas<T, Y>::SaveArchivo(string arc)
{
	bool res = true;
	ifstream archivo;
	archivo.open(arc);
	string palabra;
	if (!archivo)
	{
		res = false;
	}
	else
	{
		while (archivo >> palabra)
		{
			InsertarFirst(palabra);
		}
	}
	archivo.close();
	return res;
}

void menu()
{
	cout << "1. InsertarPrincipioLL (el)" << endl;//check
	cout << "2. EliminarTodaunasublistaLL(criterio)" << endl;//check
	cout << "3. MostrarLL()" << endl;//check
	cout << "4. BuscarRecLL (el )" << endl;//check
	cout << "5. Llenar las palabras a la LL desde un archivo" << endl;//check
	cout << "6. salir" << endl;
}

int main()
{
	ListaListas<int,string> list;
	string res;
	int op;
	int opIng;
	string palabraIng;
	do {
		cout << endl;
		menu();
		cout << "Elige una Opcion: ";
		cin >> op;
		cout << endl;
		switch (op)
		{
		case 1:
			cout << "InsertarPrincipioLL" << endl;
			cout << "Ingrese una Palabra: ";
			cin >> palabraIng;
			cout << "Verificacion de Ingreso de palabra: " << list.InsertarFirst(palabraIng) << endl;
			break;
		case 2:
			cout << "EliminarTodaunasublistaLL" << endl;
			cout << "Ingrese un criterio (tamaño de palabra): ";
			cin >> opIng;
			cout << "Verificacion de Eliminacion de lista (0 significa que no borro nada): " << list.DelletSubList(opIng) << endl;
			break;
		case 3:
			cout << "Mostrar Lista de Listas" << endl;
			list.show();
			break;
		case 4:
			cout << "BuscarR" << endl;
			cout << "Ingrese palabra a buscar: ";
			cin >> palabraIng;
			res = list.SearchElemR(palabraIng, list.getpri());
			if ( res == "-1")
			{
				cout << "Palabra no encontrada" << endl;
			}
			else
			{
				cout << "La palabra fue encontrada en la pos: " << res << " dentro la lista del criterio " << palabraIng.size()<<endl;
			}
			break;
		case 5:
			cout << "Llenar desde un archivo" << endl;
			cout << "Ingrese el nombre del archivo con la extension .txt: ";
			cin >> palabraIng;
			cout << "Verificacion de llenado: " << list.SaveArchivo(palabraIng)<<endl;
			break;
		case 6:
			cout << "Programa cerrado";
			break;
		}
	} while (op != 6);
	return 0;
}

/*
3r + 1am = 90
3am + 1az= 105
1r + 2az+ 1am= 80
1r + 2am + 1az = 95
*/
