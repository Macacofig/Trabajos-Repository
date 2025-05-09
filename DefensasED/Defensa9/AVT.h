#pragma once
#include "Nodo.h"
template <class T>
class AVT
{
private:
	Nodo<T>* raiz;  
public:
	AVT();
	Nodo<T>* Raiz();
	void Insertar(T palabra, Nodo<T>* raiz);
	bool Buscar(T palabra, Nodo<T>* raiz);
	Nodo<T>* BuscarDNodo(T palabnra, Nodo<T>* raiz);
	void Mostrar(T prefijo, Nodo<T>* raiz);
	void MostrarPalabra(T palabra, Nodo<T>* raiz);
	bool EliminarPalabra(T palabra, Nodo<T>* raiz);
};

template<class T>
AVT<T>::AVT()
{
	raiz = new Nodo<T>();
}

template<class T>
inline Nodo<T>* AVT<T>::Raiz()
{
	return raiz;
}

template<class T>
void AVT<T>::Insertar(T palabra, Nodo<T>* raiz)
{
	Nodo<T>* caminin = raiz;
	int i = 0;
	int pos;
	int tamano = palabra.size();
	while (i < tamano)
	{
		pos = palabra[i] - 'a';
		if (caminin->getVec(pos) == NULL)
		{
			caminin->setVec(pos, new Nodo<T>());
		}
		caminin = caminin->getVec(pos);
		i++;
	}
	caminin->setfin(true);
}

template<class T>
bool AVT<T>::Buscar(T palabra, Nodo<T>* raiz)
{
	bool res = false;
	Nodo<T>* caminante = raiz;
	int pos;
	int i = 0;
	int tamano = palabra.size();
	while (i < tamano && caminante != NULL)
	{
		pos = palabra[i] - 'a';
		if (caminante->getVec(pos) != NULL)
		{
			caminante = caminante->getVec(pos);
			i++;
		}
		else
		{
			caminante = NULL;
		}
	}
	if (caminante != NULL)
	{
		if (caminante->Fin() && i == tamano)
		{
			res = true;
		}
	}
	return res;
}


template<class T>
void AVT<T>::Mostrar(T prefijo, Nodo<T>* raiz)
{
	Nodo<T>* caminante = raiz;
	int pos; 
	int i = 0; 
	int tamano = prefijo.size();
	while (i < tamano && caminante != NULL)
	{
		pos = prefijo[i] - 'a'; 
		if (caminante->getVec(pos) != NULL)
		{
			caminante = caminante->getVec(pos);
			i++;
		}
		else
		{
			caminante = NULL;
		}
	}
	if (caminante != NULL)
	{
		MostrarPalabra(prefijo, caminante);
	}
}

template<class T>
void AVT<T>::MostrarPalabra(T palabra, Nodo<T>* raiz)
{
	if (raiz->Fin())
	{
		cout << palabra << endl;
	}
	for (int i = 0; i < 28; i++)
	{
		Nodo<T>* siguiente = raiz->getVec(i);
		if (siguiente != NULL)
		{
			char sig = 'a' + i;
			MostrarPalabra(palabra + sig, siguiente);
		}
	}
}

template<class T>
Nodo<T>* AVT<T>::BuscarDNodo(T palabra, Nodo<T>* raiz)
{
	Nodo<T>* res = NULL;
	Nodo<T>* caminante = raiz;
	int pos;
	int i = 0;
	int tamano = palabra.size();
	while (i < tamano && caminante != NULL)
	{
		pos = palabra[i] - 'a';
		if (caminante->getVec(pos) != NULL)
		{
			caminante = caminante->getVec(pos);
			i++;
		}
		else
		{
			caminante = NULL;
		}
	}
	if (caminante != NULL)
	{
		if (caminante->Fin() && i == tamano)
		{
			res = caminante;
		}
	}
	return res;
}

template<class T>
bool AVT<T>::EliminarPalabra(T palabra, Nodo<T>* raiz)
{
	bool res = false;
	Nodo<T>* aux = BuscarDNodo(palabra, raiz); 
	if (aux != NULL)
	{
		aux->setfin(false);
		res = true;
	}
	return res; 
}
