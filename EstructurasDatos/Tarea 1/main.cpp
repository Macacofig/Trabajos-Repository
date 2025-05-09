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

void menu()
{
    cout << "*********Menu Opciones************" << endl;
    cout << "1. Insertar Principio" << endl;
    cout << "2. Insertar Final" << endl;
    cout << "3. Eliminar Principio" << endl;
    cout << "4. Eliminar Final" << endl;
    cout << "5. Mostrar Lista" << endl;
    cout << "6. Buscar en la lista secuencialmente (No recursivo)" << endl;
    cout << "7. Ordenar la lista usando Burbuja" << endl;
    cout << "8. Salir" << endl;
}
int main()
{
    Lista2<int> list;
    int op;
    int ele;
    do {
        menu();
        cout << "Elige una opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Numero a ingresar " << endl;
            cin >> ele;
            list.Insert_First(ele);
            break;
        case 2:
            cout << "Numero a ingresar " << endl;
            cin >> ele;
            list.Insert_Last(ele);
            break;
        case 3:
            list.Delete_First();
            break;
        case 4:
            list.Delete_last();
            break;
        case 5:
            list.Show_List();
            break;
        case 6:
            cout << "Numero a Buscar " << endl;
            cin >> ele;
            cout << "Se encuentra en la pos: "<<list.search_List(ele);
            break;
        case 7:
            list.sort_Bubble();
            break;
        case 8:
            cout << "Salir";
            break;
        }
    } while (op != 8);
    return 0;
}
