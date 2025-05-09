#include <iostream>
#include <string>
#include <sstream>
#define TAM   10
using namespace std;

template <class T>
class Lista2
{
private:
    T Array[TAM];
    int PRI;
    int ULT;
public:
    Lista2();
    ~Lista2();
    int Insert_First(T el);
    int Delete_First();
    int Insert_Last(T el);
    int Delete_last();
    void Show_List();
    int search_List(T elS);
    void sort_Bubble();
    //Extras
    int getPRI();
    int getULT();
    T getEl(int pos);
    int getMax();
    void Merge(Lista2 <T> lis1, Lista2<T> lis2);
};

template <class T>
Lista2<T>::Lista2()
{
    PRI = -1;
    ULT = -1;
}

template <class T>
Lista2<T>:: ~Lista2()
{
}

template <class T>
int Lista2<T>:: getPRI()
{
    return PRI;
}

template <class T>
int Lista2<T>::getULT()
{
    return ULT;
}

template<class T>
T Lista2<T>::getEl(int pos)
{
    return Array[pos];
}

template<class T>
int Lista2<T>::getMax()
{
    return TAM;
}

template <class T>
int Lista2<T>::Insert_First(T el)
{
    int res = 1;
    if (PRI == -1)
    {
        PRI = TAM / 2;
        ULT = TAM / 2;
        Array[PRI] = el;
    }
    else
    {
        if ((PRI == 0 && ULT == TAM - 1) || (ULT + 1 == PRI))
        {
            res = 0;
        }
        else
        {
            if (PRI == 0)
            {
                PRI = TAM - 1;
            }
            else
            {
                PRI--;
            }
            Array[PRI] = el;
        }
    }
    return res;
}

template <class T>
void Lista2<T>::Show_List()
{
    int pos = PRI;
    if (PRI == -1)
    {
        cout << "No existen elementos dentro la lista";
    }
    else
    {
        while (pos != ULT)
        {
            cout << Array[pos] << ",";
            if (pos == TAM - 1)
            {
                pos = 0;
            }
            else
            {
                pos++;
            }
        }
        cout << Array[pos];
    }
    cout << endl;
}

template <class T>
int Lista2<T>::Delete_First()
{
    int res = 1;
    if (PRI == -1)
    {
        res = 0;
    }
    else
    {
        if (PRI == ULT)
        {
            PRI = -1;
            ULT = -1;
        }
        else
        {
            if (PRI == TAM - 1)
            {
                PRI = 0;
            }
            else
            {
                PRI++;
            }
        }
    }
    return res;
}

template <class T>
int Lista2<T>::Insert_Last(T el)
{
    int res = 1;
    if (ULT == -1)
    {
        PRI = TAM / 2;
        ULT = TAM / 2;
        Array[ULT] = el;
    }
    else
    {
        if ((ULT == TAM - 1 && PRI == 0) || (PRI - 1 == ULT))
        {
            res = 0;
        }
        else
        {
            if (ULT == TAM - 1)
            {
                ULT = 0;
            }
            else
            {
                ULT++;
            }
            Array[ULT] = el;
        }
    }
    return res;
}

template <class T>
int Lista2<T>::Delete_last()
{
    int res = 1;
    if (ULT == -1)
    {
        res = 0;
    }
    else
    {
        if (ULT == PRI)
        {
            ULT = -1;
            PRI = -1;
        }
        else
        {
            if (ULT == 0)
            {
                ULT = TAM - 1;
            }
            else
            {
                ULT--;
            }
        }
    }
    return res;
}

template <class T>
int Lista2<T>::search_List(T elS)
{
    int res = -1;
    int pos = PRI;
    if (PRI != -1)
    {
        while (pos != ULT)
        {
            if (Array[pos] == elS)
            {
                res = pos;
                pos = ULT;
            }
            else
            {
                if (pos == TAM - 1)
                {
                    pos = 0;
                }
                else
                {
                    pos++;
                }
            }
        }
        if (res == -1)
        {
            if (Array[pos] == elS)
            {
                res = pos;
            }
        }
    }
    return res;
}

template <class T>
void Lista2<T>::sort_Bubble()
{
    int pos;
    if (PRI != -1)
    {
        bool swape;//condicion revision cambio
        do {
            pos = PRI;
            swape = false;
            while (pos != ULT)
            {
                if (pos == TAM - 1)
                {
                    if (Array[pos] > Array[0])
                    {
                        swap(Array[pos], Array[0]);
                        swape = true;
                    }
                    pos = -1;
                }
                else
                {
                    if (Array[pos] > Array[pos + 1])
                    {
                        swap(Array[pos], Array[pos + 1]);
                        swape = true;
                    }
                }
                pos++;
            }

        } while (swape);
    }
}
template<class T>
void Lista2<T> ::Merge(Lista2<T> lis1, Lista2<T> lis2)
{
    int P1, P2,i = 1;
    int control1 = 0,control2 = 0; // controles de elementos en listas
    P1 = lis1.getPRI(),P2 = lis2.getPRI(); //primeros de cada lista
    if (P1 != -1 && P2 != -1)
    {
        while (control1 == 0 || control2 == 0)
        {
            if (i == 1)
            {
                if (P1 == -1)
                {
                    i = 2;
                    control1 = 1;
                }
                else
                {
                    if (control1 != 1) // aun no puso el ultimo elemento
                    {
                        if (P1 == lis1.getULT()) //ultimo elemento de la lista
                        {
                            Insert_Last(lis1.getEl(P1));
                            i = 2;
                            control1 = 1;
                        }
                        else
                        {
                            if (P1 == lis1.getMax() - 1) // 
                            {
                                Insert_Last(lis1.getEl(P1));
                                i = 2;
                                P1 = 0;
                            }
                            else
                            {
                                Insert_Last(lis1.getEl(P1));
                                i = 2;
                                P1++;
                            }
                        }
                    }
                    else //ir a otra lista
                    {
                        i=2;
                    }
                }
            }
            else
            {
                if (P2 == -1)
                {
                    i = 1;
                    control2 = 1;
                }
                else
                {
                    if (control2 != 1)
                    {
                        if (P2 == lis2.getULT())
                        {
                            Insert_Last(lis2.getEl(P2));
                            i = 1;
                            control2 = 1;
                        }
                        else
                        {
                            if (P2 == lis2.getMax() - 1)
                            {
                                Insert_Last(lis2.getEl(P2));
                                i = 1;
                                P2 = 0;
                            }
                            else
                            {
                                Insert_Last(lis2.getEl(P2));
                                i = 1;
                                P2++;
                            }
                        }
                    }
                    else
                    {
                        i = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    Lista2<int> list1,list2,list3;

    list1.Insert_Last(1);
    list1.Insert_Last(2);
    list1.Insert_Last(3);
    list1.Insert_Last(4);
    list1.Insert_Last(5);
    cout << "Lista 1:" << endl;
    list1.Show_List();

    list2.Insert_Last(0);
    list2.Insert_Last(0);
    cout << "Lista 2:" << endl;
    list2.Show_List();
    list3.Merge(list1, list2);
    list3.Show_List();
    return 0;
}