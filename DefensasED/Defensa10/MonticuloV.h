#pragma once
#include <math.h>
#include <vector>
#include "Nodo.h"
#define TAM 300000

template <class T>
class MonticuloV
{
private:
    vector<Nodo<T>*> vec;
    int last;

public:
    MonticuloV();
    ~MonticuloV();
    vector<Nodo<T>*> getVec();
    void INSERTAR(T el);
    void Recuperar_D_U(int hoja);
    void Recuperar_U_D(int hoja);
    int ELIMINAR();
    string ELIMINARS();
    void MOSTRAR();
    void LEERARCHIVO(string nombre);
    void sort(string nombre);
};

template<class T>
MonticuloV <T>::MonticuloV() : vec(TAM)
{
    last = 0;
    for (int i = 0; i < TAM; i++)
    {
        vec[i] = new Nodo<T>();
    }
}

template<class T>
MonticuloV <T>::~MonticuloV()
{
}

template<class T>
std::vector<Nodo<T>*> MonticuloV<T>::getVec()
{
    return vec;
}

template<class T>
void MonticuloV<T>::INSERTAR(T el)
{
    if (last == 0)
    {
        last = 1;
        vec[last]->setDato(el);
        vec[last]->setExiste(true);
    }
    else
    {
        last = last + 1;
        vec[last]->setDato(el);
        vec[last]->setExiste(true);
        Recuperar_D_U(last);
    }
}

template<class T>
void MonticuloV<T>::Recuperar_D_U(int hoja)
{
    if (hoja / 2 > 0)
    {
        if (vec[hoja]->Dato() < vec[hoja / 2]->Dato())
        {
            std::swap(vec[hoja], vec[hoja / 2]);
            Recuperar_D_U(hoja / 2);
        }
    }
}

template<class T>
void MonticuloV<T>::Recuperar_U_D(int hoja)
{
    if (2 * hoja < last && vec[2 * hoja]->Existe() && vec[(2 * hoja) + 1]->Existe())
    {
        if (vec[2 * hoja]->Dato() < vec[(2 * hoja) + 1]->Dato())
        {
            if (vec[2 * hoja]->Dato() < vec[hoja]->Dato())
            {
                std::swap(vec[2 * hoja], vec[hoja]);
                Recuperar_U_D(2 * hoja);
            }
        }
        else
        {
            if (vec[(2 * hoja) + 1]->Dato() < vec[hoja]->Dato())
            {
                std::swap(vec[(2 * hoja) + 1], vec[hoja]);
                Recuperar_U_D((2 * hoja) + 1);
            }
        }
    }
    else if (2 * hoja < last && vec[2 * hoja]->Existe())
    {
        if (vec[2 * hoja]->Dato() < vec[hoja]->Dato())
        {
            std::swap(vec[2 * hoja], vec[hoja]);
        }
    }
}

template<class T>
int MonticuloV<T>::ELIMINAR()
{
    int res;
    if (last == 0)
    {
        res = -10000;
    }
    else
    {
        res = vec[1]->Dato();
        vec[1]->setDato(vec[last]->Dato());
        vec[last]->setExiste(false);
        last = last - 1;
        Recuperar_U_D(1);
    }
    return res;
}

template<class T>
string MonticuloV<T>::ELIMINARS()
{
    string res;
    if (last == 0)
    {
        res = "VACIO";
    }
    else
    {
        res = vec[1]->Dato();
        vec[1]->setDato(vec[last]->Dato());
        vec[last]->setExiste(false);
        last = last - 1;
        Recuperar_U_D(1);
    }
    return res;
}

template<class T>
void MonticuloV<T>::MOSTRAR()
{
    int fila = 0;
    int control = 1;
    if (last != 0)
    {
        for (int i = 1; i <= last; i++)
        {
            cout << vec[i]->Dato();
            if (control == pow(2, fila))
            {
                cout << " {***}" << endl;
                fila = fila + 1;
                control = 1;
            }
            else
            {
                cout << "/";
                control = control + 1;
            }
        }
    }
    cout << endl;
}

template<class T>
void MonticuloV<T>::LEERARCHIVO(string nombre)
{
    fstream arch;
    arch.open(nombre);
    string linea;
    if (!arch)
    {
        cout << "error" << endl;
    }
    while (arch >> linea)
    {
        cout << linea<<endl;
        INSERTAR(linea);
    }
    arch.close();
}

template<class T>
void MonticuloV<T>::sort(string nombre)
{
    LEERARCHIVO(nombre);
    ofstream archivo("Ordenado.txt");
    string palabra;
    int i = 1;
    if (!archivo.is_open()) 
    {
        cout << "Error al abrir el archivo " << endl;
        return;
    }
    else
    {
        while (last != 0)
        {
            palabra = ELIMINARS();
            archivo << palabra << endl;
        }
    }
    
}
