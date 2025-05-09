#pragma once
#include "Nodo.h"
template <class T>
class AVL
{
private:
    Nodo<T>* Raiz;

public:
    AVL();
    ~AVL();
    Nodo<T>* getRaiz();
    Nodo<T>*& getRaizRef();
    void insert(T el, Nodo<T>*& raiz, string& next);
    void RotarLeftSimple(Nodo<T>*& raiz);
    void RotarRightSimple(Nodo<T>*& raiz);
    void RotarLeftCom(Nodo<T>*& raiz);
    void RotarRightCom(Nodo<T>*& raiz);
    int NodoCount(Nodo<T>* raiz);
    int Altura(Nodo<T>* raiz);
    void ShowInOrder(Nodo<T>* raiz);
    void ShowPreOrder(Nodo<T>* raiz);
    void ShowPostOrder(Nodo<T>* raiz);
    Nodo<T>* BuscarMayor(Nodo<T>* raiz);
    Nodo<T>* BuscarMenor(Nodo<T>* raiz);
    void DeleteAll(int nivel, Nodo<T>*& raiz, int nivelActual);
    void InsertDictionary(string name);

    int countHojas(Nodo<T>* raiz);
    void MostrarNivel(Nodo<T>* raiz, int niveclactual, int nivelmostrar);
    void MostrarNiveles(Nodo<T>* raiz);
};

template<class T>
AVL<T>::AVL()
{
    Raiz = NULL;
}

template<class T>
AVL<T>::~AVL()
{
}

template<class T>
Nodo<T>* AVL<T>::getRaiz()
{
    return Raiz;
}

template<class T>
Nodo<T>*& AVL<T>::getRaizRef()
{
    return Raiz;
}

template<class T>
void AVL<T>::insert(T el, Nodo<T>*& raiz, string& next)
{
    if (raiz == NULL)
    {
        Nodo<T>* nodo = new Nodo<T>();
        nodo->setDato(el);
        nodo->setFactor(0);
        raiz = nodo;
        next = "si";
    }
    else
    {
        if (el < raiz->Dato())
        {
            insert(el, raiz->getLRef(), next);
            if (next == "si")
            {
                raiz->setFactor(raiz->Fac() + 1);
                if (raiz->Fac() == 0)
                {
                    next = "no";
                }
                else
                {
                    if (raiz->Fac() == 2)
                    {
                        next = "no";
                        if (raiz->getLeft()->Fac() == 1)
                        {
                            RotarRightSimple(raiz);
                        }
                        else
                        {
                            RotarRightCom(raiz);
                        }
                    }
                }
            }
        }
        if (el > raiz->Dato())
        {
            insert(el, raiz->getRRef(), next);
            if (next == "si")
            {
                raiz->setFactor(raiz->Fac() - 1);
                if (raiz->Fac() == 0) 
                {
                    next = "no"; 
                }
                else
                {
                    if (raiz->Fac() == -2)
                    {
                        next = "no"; 
                        if (raiz->getRight()->Fac() == -1) 
                        {
                            RotarLeftSimple(raiz);
                        }
                        else
                        {
                            RotarLeftCom(raiz);
                        }
                    }
                }
            }
        }
    }
}

template<class T>
void AVL<T>::RotarLeftSimple(Nodo<T>*& raiz)
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
    raiz->setFactor(0);
    raiz->getLeft()->setFactor(0); 
}

template<class T>
void AVL<T>::RotarRightSimple(Nodo<T>*& raiz)
{
    Nodo<T>* nraiz = raiz->getLeft();
    Nodo<T>* flotante = NULL;
    if (nraiz->getRight() != NULL) 
    {
        flotante = nraiz->getRight();
    }
    nraiz->setRight(raiz);
    raiz->setLeft(flotante);
    raiz = nraiz;
    raiz->setFactor(0); 
    raiz->getRight()->setFactor(0); 
}

template<class T>
void AVL<T>::RotarLeftCom(Nodo<T>*& raiz)
{
    Nodo<T>* nraiz = raiz->getRight()->getLeft(); 
    Nodo<T>* Fizq = nraiz->getLeft(); 
    Nodo<T>* Fdere = nraiz->getRight(); 
    raiz->getRight()->setLeft(Fdere);
    nraiz->setRight(raiz->getRight());
    raiz->setRight(Fizq); 
    nraiz->setLeft(raiz); 
    raiz = nraiz; 
    if (raiz->Fac() == 0) 
    {
        raiz->getLeft()->setFactor(0); 
        raiz->getRight()->setFactor(0); 
    }
    if (raiz->Fac() == 1)
    {
        raiz->getLeft()->setFactor(0);
        raiz->getRight()->setFactor(-1);
    }
    if (raiz->Fac() == -1)
    {
        raiz->getLeft()->setFactor(1);
        raiz->getRight()->setFactor(0);
    }
    raiz->setFactor(0);
}

template<class T>
void AVL<T>::RotarRightCom(Nodo<T>*& raiz)
{
    Nodo<T>* nraiz = raiz->getLeft()->getRight();
    Nodo<T>* Fizq = nraiz->getLeft();
    Nodo<T>* Fdere = nraiz->getRight();
    raiz->getLeft()->setRight(Fizq);
    nraiz->setLeft(raiz->getLeft());
    raiz->setLeft(Fdere);
    nraiz->setRight(raiz);
    raiz = nraiz;
    if (raiz->Fac() == 0)
    {
        raiz->getLeft()->setFactor(0);
        raiz->getRight()->setFactor(0);
    }
    if (raiz->Fac() == 1)
    {
        raiz->getLeft()->setFactor(0);
        raiz->getRight()->setFactor(-1);
    }
    if (raiz->Fac() == -1)
    {
        raiz->getLeft()->setFactor(1);
        raiz->getRight()->setFactor(0);
    }
    raiz->setFactor(0);
}

template<class T>
int AVL<T>::NodoCount(Nodo<T>* raiz)
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

template<class T>
int AVL<T>::Altura(Nodo<T>* raiz)
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
void AVL<T>::ShowInOrder(Nodo<T>* raiz)
{
    if (raiz == NULL)
    {
        cout << "";
    }
    else
    {
        ShowInOrder(raiz->getLeft());
        cout << raiz->Dato() << "<" << raiz->Fac() << ">" << " / ";
        ShowInOrder(raiz->getRight());
    }
}

template<class T>
void AVL<T>::ShowPreOrder(Nodo<T>* raiz)
{
    if (raiz == NULL)
    {
        cout << "";
    }
    else
    {
        cout << raiz->Dato() << raiz->Fac() << " / ";
        ShowInOrder(raiz->getLeft());
        ShowInOrder(raiz->getRight());
    }
}

template<class T>
void AVL<T>::ShowPostOrder(Nodo<T>* raiz)
{
    if (raiz == NULL)
    {
        cout << "";
    }
    else
    {
        ShowInOrder(raiz->getLeft());
        ShowInOrder(raiz->getRight());
        cout << raiz->Dato() << raiz->Fac() << " / ";
    }
}

template<class T>
Nodo<T>* AVL<T>::BuscarMayor(Nodo<T>* raiz)
{
    Nodo<T>* aux = raiz;
    if (aux != NULL)
    {
        if (aux->getRight() != NULL)
        {
            aux =BuscarMayor(aux->getRight()); 
        } 
    }
    return aux;
}

template<class T>
inline Nodo<T>* AVL<T>::BuscarMenor(Nodo<T>* raiz)
{
    Nodo<T>* aux = raiz; 
    if (aux != NULL) 
    {
        if (aux->getLeft() != NULL)
        {
            aux = BuscarMenor(aux->getLeft()); 
        }
    }
    return aux; 
}

template<class T>
void AVL<T>::DeleteAll(int nivel, Nodo<T>*& raiz, int nivelActual)
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

    template<class T>
    void AVL<T>::InsertDictionary(string name)
    {
        ifstream archivo; 
        string c;
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
                cout << auxw << endl; 
                insert(auxw, getRaizRef(), c); 
            }
        }
        archivo.close(); 
    }

template<class T>
int AVL<T>::countHojas(Nodo<T>* raiz)
{
    int res;
    int res1;
    int res2;
    if (raiz != NULL)
    {
        if (raiz->getLeft() == NULL || raiz->getRight() == NULL) 
        {
            res = 1; 
        }
        else
        {
            res1 = countHojas(raiz->getLeft());
            res2 = countHojas(raiz->getRight());
            res = res1 + res2;
        }
    }
    return res;  
}

template<class T>
void AVL<T>::MostrarNivel(Nodo<T>* raiz, int niveclactual, int nivelmostrar) 
{
    if (raiz != NULL)
    {
        if (niveclactual == nivelmostrar) 
        {
            cout << raiz->Dato() << "<" << raiz->Fac() << "> ";
        }
        else if (niveclactual < nivelmostrar)
        {
            MostrarNivel(raiz->getLeft(), niveclactual + 1, nivelmostrar); 
            MostrarNivel(raiz->getRight(), niveclactual + 1, nivelmostrar); 
        }
    }
    
}
template<class T>
void AVL<T>::MostrarNiveles(Nodo<T>* raiz)
{
    int altura = Altura(raiz); 

    for (int nivel = 1; nivel <= altura; nivel++) 
    {
        cout << "Nivel " << nivel - 1 << ": ";
        MostrarNivel(raiz, 1, nivel);
        cout << endl;
    }
}
