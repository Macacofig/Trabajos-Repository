#pragma once
#include "Nodo.h"
template <class T>
class ArbolRojoNegro
{
private:
    Nodo<T>* Raiz;

public:
    ArbolRojoNegro();
    ~ArbolRojoNegro();
    Nodo<T>* getRaiz();
    Nodo<T>*& getRaizRef();
    void insert(T el, Nodo<T>*& raiz, string& next, string& lado, string& pari);
    void RotarLeft(Nodo<T>*& raiz);
    void RotarRight(Nodo<T>*& raiz);
    int NodoCount(Nodo<T>* raiz);
    int Altura(Nodo<T>* raiz);
    void ShowInOrder(Nodo<T>* raiz);
    void ShowPreOrder(Nodo<T>* raiz);
    void ShowPostOrder(Nodo<T>* raiz);
    Nodo<T>* Buscar(T el, Nodo<T>* raiz);
    void DeleteAll(int nivel, Nodo<T>*& raiz, int nivelActual);
    void InsertDictionary(string name);
};

template <class T>
ArbolRojoNegro<T>::ArbolRojoNegro()
{
    Raiz = NULL;
}

template <class T>
ArbolRojoNegro<T>::~ArbolRojoNegro()
{
    DeleteAll(0, getRaizRef(), 1);
}

template <class T>
Nodo<T>* ArbolRojoNegro<T>::getRaiz()
{
    return Raiz;
}

template <class T>
Nodo<T>*& ArbolRojoNegro<T>::getRaizRef()
{
    return Raiz;
}

template <class T>
void ArbolRojoNegro<T>::insert(T el, Nodo<T>*& raiz, string& next, string& lado, string& pari)
{
    if (raiz == NULL)
    {
        Nodo<T>* nuevo = new Nodo<T>();
        nuevo->setDato(el);
        nuevo->setColor('R');
        raiz = nuevo;
        next = "si";
        pari = "par";
    }
    else
    {
        if (el < raiz->getDato())
        {
            insert(el, raiz->getLRef(), next, lado, pari);
            if (next == "si")
            {
                if (pari == "par")
                {
                    if (raiz->getColor() == 'N')
                    {
                        next = "no";
                    }
                    else
                    {
                        pari = "impar";
                        lado = "izq";
                    }
                }
                else
                {
                    if (pari == "impar")
                    {
                        if (raiz->getRRef() != NULL && raiz->getRRef()->getColor() == 'R')
                        {
                            raiz->getLRef()->setColor('N');
                            raiz->getRRef()->setColor('N');
                            raiz->setColor('R');
                            pari = "par";
                        }
                        else
                        {
                            next = "no";
                            if (lado == "dere")
                            {
                                RotarLeft(raiz->getLRef());
                            }
                            raiz->getLeft()->setColor('N');
                            raiz->setColor('R');
                            RotarRight(raiz);
                        }
                    }
                }
            }
        }
        if (el > raiz->getDato())
        {
            insert(el, raiz->getRRef(), next, lado, pari);
            if (next == "si")
            {
                if (pari == "par")
                {
                    if (raiz->getColor() == 'N')
                    {
                        next = "no";
                    }
                    else
                    {
                        pari = "impar";
                        lado = "dere";
                    }
                }
                else
                {
                    if (pari == "impar")
                    {
                        if (raiz->getLRef() != NULL && raiz->getLRef()->getColor() == 'R')
                        {
                            raiz->getLRef()->setColor('N');
                            raiz->getRRef()->setColor('N');
                            raiz->setColor('R');
                            pari = "par";
                        }
                        else
                        {
                            next = "no";
                            if (lado == "izq")
                            {
                                RotarRight(raiz->getRRef());
                            }
                            raiz->getRRef()->setColor('N');
                            raiz->setColor('R');
                            RotarLeft(raiz);
                        }
                    }
                }
            }
        }
    }
}

template <class T>
void ArbolRojoNegro<T>::RotarLeft(Nodo<T>*& raiz)
{
    Nodo<T>* nraiz = raiz->getRight();
    Nodo<T>* flotante = NULL;
    if (nraiz->getLeft() != NULL)
    {
        flotante = nraiz->getLeft();
    }
    nraiz->setLeft(raiz);
    raiz->setRight(flotante);
    raiz = nraiz;
}

template <class T>
void ArbolRojoNegro<T>::RotarRight(Nodo<T>*& raiz)
{
    Nodo<T>* nraiz = raiz->getLeft();
    Nodo<T>* flotante = NULL;
    if (nraiz->getLeft() != NULL)
    {
        flotante = nraiz->getRight();
    }
    nraiz->setRight(raiz);
    raiz->setLeft(flotante);
    raiz = nraiz;
}

template <class T>
int ArbolRojoNegro<T>::NodoCount(Nodo<T>* raiz)
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
        res1 = NodoCount(raiz->getRight());
        res2 = NodoCount(raiz->getLeft());
        res = res1 + res2 + 1;
    }
    return res;
}

template <class T>
int ArbolRojoNegro<T>::Altura(Nodo<T>* raiz)
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

template <class T>
void ArbolRojoNegro<T>::ShowInOrder(Nodo<T>* raiz)
{
    if (raiz == NULL)
    {
        cout << "";
    }
    else
    {
        ShowInOrder(raiz->getLeft());
        cout << raiz->getDato() << raiz->getColor() << " / ";
        ShowInOrder(raiz->getRight());
    }
}

template <class T>
void ArbolRojoNegro<T>::ShowPreOrder(Nodo<T>* raiz)
{
    if (raiz == NULL)
    {
        cout << "";
    }
    else
    {
        cout << raiz->getDato() << raiz->getColor() << " / ";
        ShowInOrder(raiz->getLeft());
        ShowInOrder(raiz->getRight());
    }
}

template <class T>
void ArbolRojoNegro<T>::ShowPostOrder(Nodo<T>* raiz)
{
    if (raiz == NULL)
    {
        cout << "";
    }
    else
    {
        ShowInOrder(raiz->getLeft());
        ShowInOrder(raiz->getRight());
        cout << raiz->getDato() << raiz->getColor() << " / ";
    }
}

template <class T>
Nodo<T>* ArbolRojoNegro<T>::Buscar(T el,Nodo<T>* raiz)
{
    Nodo<T>* aux = NULL;
    if (raiz == NULL)
    {
        aux = NULL;
    }
    else
    {
        if (el < raiz->getDato())
        {
            aux = Buscar(el, raiz->getLeft());
        }
        if (el > raiz->getDato())
        {
            aux = Buscar(el, raiz->getRight());
        }
        if (el == raiz->getDato())
        {
            aux = raiz;
        }
    }
    return aux;
}

template <class T>
void ArbolRojoNegro<T>::DeleteAll(int nivel, Nodo<T>*& raiz, int nivelActual)
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
            DeleteAll(nivel, raiz->getLRef(), nivelActual + 1);
            DeleteAll(nivel, raiz->getRRef(), nivelActual + 1);
        }

    }
}

template <class T>
void ArbolRojoNegro<T>::InsertDictionary(string name)
{
    ifstream archivo;
    string c = "";
    string p = "";
    string l = "";
    T auxw;
    
    archivo.open(name);
    if (!archivo)
    {
        cout << "Error";
    }
    else
    {
        while (archivo >> auxw) 
        {
            c = "";
            p = "";
            l = "";
            cout << auxw << endl;
            insert(auxw,getRaizRef(),c,l,p);
        }
    }
    archivo.close();
}

