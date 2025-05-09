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
	bool Insert_First(T el);
	bool Delete_First();
	bool Insert_Last(T el);
	bool Delete_Last();
	bool Delete_All();
	void Show();
	T Search_Pos(int pos);
	int Search_DateNR(T el);
	int Search_DateR(T el,Nodo<T>* aux,int pos);
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
Nodo<T>* Lista8<T>:: getpri()
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
int Lista8<T>::Search_DateR(T el,Nodo<T>* aux,int pos)
{
	int res;
	if (pri == NULL)
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
			if (aux == NULL)
			{
				res = -1;
			}
			else
			{
				res = Search_DateR(el, aux->getSig(), pos + 1);
			}
		}
	}
	return res;
}
/************************************* */
void menu()
{
	cout << "1. Insertar Principio" << endl;
	cout << "2. Insertar Final" << endl;
	cout << "3. Eliminar Principio" << endl;
	cout << "4. Eliminar Final" << endl;
	cout << "5. Eliminar toda la lista" << endl;
	cout << "6. Buscar elemento de una posicion" << endl;
	cout << "7. Mostrar Lista" << endl;
	cout << "8. Buscar en la lista secuencialmente (No recursivo)" << endl;
	cout << "9. Buscar (Recursivo)" << endl;
	cout << "10. salir" << endl;
}
int main()
{
	Lista8<char> lista;
	int op;
	int pos;
	char el;
	do {
		menu();
		cout << "Ingrese una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Ingrese el dato a ingresar: ";
			cin >> el;
			cout << endl;
			cout << lista.Insert_First(el) << endl;
			break;
		case 2:
			cout << "Ingrese el dato a ingresar: ";
			cin >> el;
			cout << endl;
			cout << lista.Insert_Last(el) << endl;
			break;
		case 3:
			cout << "Verificacion de eliminacion: " << lista.Delete_First() << endl;
			break;
		case 4:
			cout << "Verificacion de eliminacion: " << lista.Delete_Last() << endl;
			break;
		case 5:
			cout << "Verificacion de eliminacion: " << lista.Delete_All() << endl;
			break;
		case 6:
			cout << "Elija una posicion: ";
			cin >> pos;
			cout << endl;
			cout << "Dato en la pos " << pos << " (Sale 0 *no hay dato*): " << lista.Search_Pos(pos) << endl;
			break;
		case 7:
			cout << "Elementos de la lista:" << endl;
			lista.Show();
			break;
		case 8:
			cout << "Elija un dato a buscar: ";
			cin >> el;
			cout << endl;
			cout << "Dato encontrado en la pos (Sale -1 *no hay dato*): " << lista.Search_DateNR(el) << endl;
			break;
		case 9:
			cout << "Elija un dato a buscar: ";
			cin >> el;
			cout << endl;
			cout << "Dato encontrado en la pos (Sale -1 *no hay dato*): " << lista.Search_DateR(el,lista.getpri(),1) << endl;
			break;
		case 10:
			cout << "Programa finalizado" << endl;
			break;
		}
	} while (op != 10);
	return 0;
}