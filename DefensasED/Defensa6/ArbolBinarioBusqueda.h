#pragma once
#include "Nodo.h"
template <class T>
class ArbolBinarioBusqueda
{
private:
	Nodo<T>* Raiz;
public:
	ArbolBinarioBusqueda();
	~ArbolBinarioBusqueda();
	Nodo<T>* getRaiz();
	Nodo<T>*& getRaizRef();
	void insertar(T el, Nodo<T>*& R);//1
	int contarNodo(Nodo<T>* raiz);
	int Altura(Nodo<T>* raiz);
	void ShowInOrder(Nodo<T>* raiz);
	void ShowPreOrder(Nodo<T>* raiz);
	void ShowPostOrder(Nodo<T>* raiz);
	Nodo<T>* Mayor(Nodo<T>* raiz);
	Nodo<T>* menor(Nodo<T>* raiz);
	Nodo<T>* Buscar(T el, Nodo<T>* raiz);
	bool eliminar(T el, Nodo<T>* raiz);
	void NivelePoda(int nivel, Nodo<T>*& raiz, int nivelActual);
};

template<class T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda()
{
	Raiz = NULL;
}

template<class T>
ArbolBinarioBusqueda<T>::~ArbolBinarioBusqueda()
{
	NivelePoda(0, getRaizRef(), 1);
}

template<class T>
Nodo<T>* ArbolBinarioBusqueda<T>::getRaiz()
{
	return Raiz; 
}

template<class T>
Nodo<T>*& ArbolBinarioBusqueda<T>::getRaizRef()
{
	return Raiz;
}

template<class T>
void ArbolBinarioBusqueda<T>::insertar(T el, Nodo<T>*& R)
{
	if (R == NULL)
	{
		R = new Nodo<T>();
		R->setDato(el); 
	}
	else
	{
		if (el < R->getDato())
		{
			insertar(el, R->getLRef()); 
		}
		if (el > R->getDato())
		{
			insertar(el, R->getRRef());
		}
	}
}

template<class T>
int ArbolBinarioBusqueda<T>::contarNodo(Nodo<T>* raiz)
{
	int res;
	int res1;
	int res2;
	if (raiz == NULL)
	{
		res = 0;
	}
	else
	{
		res1 = contarNodo(raiz->getRight());
		res2 = contarNodo(raiz->getLeft());
		res = res1 + res2 + 1;
	}
	return res;
}

template<class T>
int ArbolBinarioBusqueda<T>::Altura(Nodo<T>* raiz)
{
	int res;
	int res1;
	int res2;
	if (raiz == NULL)
	{
		res = 0;
	}
	else
	{
		res1 = Altura(raiz->getRight());
		res2 = Altura(raiz->getLeft());
		if (res1 > res2)
		{
			res = res1 + 1;
		}
		else
		{
			res = res2 + 1;
		}
	}
	return res;
}

 template<class T>
 void ArbolBinarioBusqueda<T>::ShowInOrder(Nodo<T>* raiz)
 {
	  if (raiz == NULL)
	  {
		  cout << "";
	  }
	  else
	  {
		  ShowInOrder(raiz->getLeft());
		  cout << raiz->getDato() << " / ";
		  ShowInOrder(raiz->getRight()); 
	  }
 }

 template<class T>
 void ArbolBinarioBusqueda<T>::ShowPreOrder(Nodo<T>* raiz)
 {
	 if (raiz == NULL)
	 {
		 cout << "";
	 }
	 else
	 {
		 cout << raiz->getDato() << " / ";
		 ShowInOrder(raiz->getLeft());
		 ShowInOrder(raiz->getRight());
	 }
 }

 template<class T>
  void ArbolBinarioBusqueda<T>::ShowPostOrder(Nodo<T>* raiz)
 {
	  if (raiz == NULL)
	  {
		  cout << "";
	  }
	  else
	  {
		  ShowInOrder(raiz->getLeft());
		  ShowInOrder(raiz->getRight());
		  cout << raiz->getDato() << " / ";
	  }
 }

  template<class T>
  Nodo<T>* ArbolBinarioBusqueda<T>::Mayor(Nodo<T>* raiz)
  {
	  Nodo<T>* aux;
	  if (raiz == NULL)
	  {
		  aux = NULL;
	  }
	  else
	  {
		  if (raiz->getRight() == NULL)
		  {
			  aux = raiz;
		  }
		  else
		  {
			  aux = Mayor(raiz->getRight());
		  }
	  }
	  return aux;  
  }

  template<class T>
  Nodo<T>* ArbolBinarioBusqueda<T>::menor(Nodo<T>* raiz)
  {
	  Nodo<T>* aux; 
	  if (raiz == NULL) 
	  {
		  aux = NULL; 
	  }
	  else
	  {
		  if (raiz->getLeft() == NULL)
		  {
			  aux = raiz;
		  }
		  else
		  {
			  aux = menor(raiz->getLeft());
		  }
	  }
	  return aux;
  }

  template<class T>
  Nodo<T>* ArbolBinarioBusqueda<T>::Buscar(T el, Nodo<T>* raiz)
  {
	  Nodo<T>* aux= NULL;
	  if (raiz == NULL)
	  {
		  aux = NULL;
	  }
	  else
	  {
		  if (el < raiz->getDato())
		  {
			  aux =Buscar(el, raiz->getLeft());
		  }
		  if (el > raiz->getDato()) 
		  {
			  aux =Buscar(el, raiz->getRight()); 
		  }
		  if (el == raiz->getDato())
		  {
			  aux = raiz; 
		  }
	  }
	  return aux;
  }

  template<class T>
  bool ArbolBinarioBusqueda<T>::eliminar(T el, Nodo<T>* raiz)
  {
	  bool res = true;
	  if (raiz == NULL)
	  {
		  res = false;
	  }
	  else
	  {
		  if (el < raiz->getDato())
		  {
			  res = eliminar(el, raiz->getLeft());
		  }
		  if (el > raiz->getDato()) 
		  {
			  res = eliminar(el, raiz->getRight());
		  }
		  if (el == raiz->getDato())
		  {
			  if (raiz->getLeft() == NULL && raiz->getRight() == NULL)
			  {
				  raiz = NULL;  
				  delete raiz;
			  }
			  else
			  {
				  if (raiz->getLeft() != NULL)
				  {
					  Nodo<T>* mayormenores = Mayor(raiz->getLeft()); 
					  raiz->setDato(mayormenores->getDato());
					  res = eliminar(mayormenores->getDato(), raiz->getLeft());
				  }
				  else
				  {
					  Nodo<T>* menormayores = menor(raiz->getRight()); 
					  raiz->setDato(menormayores->getDato());
					  res = eliminar(menormayores->getDato(), raiz->getRight());
				  }
			  }
		  }
	  }
	  return res;
  }

  template<class T>
  void ArbolBinarioBusqueda<T>::NivelePoda(int nivel, Nodo<T>*& raiz, int nivelActual)
  {
	  if (raiz != NULL)
	  {
		  if (nivelActual > nivel)
		  {
			  delete raiz;
			  raiz = NULL;
		  }
		  else
		  {
			  NivelePoda(nivel, raiz->getLRef(), nivelActual + 1);
			  NivelePoda(nivel, raiz->getRRef(), nivelActual + 1);
		  }
		  
	  }
  }
