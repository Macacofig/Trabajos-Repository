#pragma once
#include "Nodo.h"
#include <cstdlib>
#include <ctime>
#define TAM 100
template <class T>
class ArbolBinario
{
private:
	Nodo<T> vec[TAM];
public:
    ArbolBinario();
    ~ArbolBinario();
    bool InsertAleatory(T el, int pos);
    int CountNodos(int pos);
    int Altura(int pos);
    void ShowInOrder(int pos);
    void ShowPreOrder(int pos);
    void ShowPostOrder(int pos);
    bool podaHojas(int pos);
};

template<class T>
ArbolBinario<T>::ArbolBinario()
{
}

template<class T>
 ArbolBinario<T>::~ArbolBinario()
{
}

template<class T>
 bool ArbolBinario<T>::InsertAleatory(T el, int pos)
{
    int lado;
    if (vec[pos].getExist() == false)
    {
        vec[pos].setDato(el);
        vec[pos].setExist(true);
    }
    else
    {
        lado = rand() % 2;
        if (lado == 1) //right
        {
            cout << "R";
            InsertAleatory(el, (pos * 2) + 1);
        }
        else // left
        {
            cout << "L";
            InsertAleatory(el, pos * 2);
        }
    }
    return true;
}

template<class T>
int ArbolBinario<T>::CountNodos(int pos)
{
    int res;
    int res1;
    int res2;
    if (vec[pos].getExist() == false)
    {
        res = 0;
    }
    else
    {
        res1 = CountNodos((pos * 2) + 1);
        res2 = CountNodos((pos * 2));
        res = res1 + res2 + 1;
    }
    return res;
}

template<class T>
 int ArbolBinario<T>::Altura(int pos)
{
    int res;
    int res1;
    int res2;
    if (vec[pos].getExist() == false)
    {
        res = 0;
    }
    else
    {
        res1 = Altura((pos * 2) + 1);
        res2 = Altura((pos * 2));
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
 void ArbolBinario<T>::ShowInOrder(int pos)
{
    if (vec[pos].getExist() == false)
    {
        cout << "";
    }
    else
    {
        ShowInOrder(pos * 2);
        cout << vec[pos].getDato() << " / ";
        ShowInOrder((pos * 2) + 1);
    }
}

template<class T>
 void ArbolBinario<T>::ShowPreOrder(int pos)
{
    if (vec[pos].getExist() == false)
    {
        cout << "";
    }
    else
    {
        cout << vec[pos].getDato() << " / ";
        ShowPreOrder(pos * 2);
        ShowPreOrder((pos * 2) + 1);
    }
}

template<class T>
 void ArbolBinario<T>::ShowPostOrder(int pos)
{
    if (vec[pos].getExist() == false)
    {
        cout << "";
    }
    else
    {
        ShowPostOrder(pos * 2);
        ShowPostOrder((pos * 2) + 1);
        cout << vec[pos].getDato() << " / ";
    }
}

template<class T>
bool ArbolBinario<T>::podaHojas(int pos)
{
    bool res;
    if (vec[pos].getExist() == false)
    {
        res = false;
    }
    else
    {
        if (vec[(pos * 2) + 1].getExist() == true || vec[pos * 2].getExist() == true)
        {
            podaHojas((pos * 2) + 1);
            podaHojas((pos * 2));
        }
        else
        {
            vec[pos].setExist(false);
            res = true;
        }
    }
    return res;
}
