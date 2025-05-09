#pragma once
#include <math.h>
#include <vector>
#include "NodoM.h"
#define TAM 10

template <class T>
class MonticuloV
{
private:
    vector<NodoM<T>*> vec;
    int last;

public:
    MonticuloV();
    ~MonticuloV();
    int getlast();
    vector<NodoM<T>*> getVec();
    void INSERTAR(T el);
    void Recuperar_D_U(int hoja);
    void Recuperar_U_D(int hoja);
    T ELIMINAR();
    void mostrarcolaP();
};

template<class T>
MonticuloV <T>::MonticuloV()
{
    last = 0;
    vec.resize(TAM, nullptr);
    for (int i = 0; i < TAM; i++)
    {
        vec[i] = new NodoM<T>();
    }
}

template<class T>
MonticuloV <T>::~MonticuloV()
{
}

template<class T>
int MonticuloV<T>::getlast()
{
    return last;
}

template<class T>
vector<NodoM<T>*> MonticuloV<T>::getVec()
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
   // cout << "Entra Recuperar_D_U" << endl;
    if (hoja / 2 > 0)
    {
        if (vec[hoja]->Dato() < vec[hoja / 2]->Dato())
        {
           // cout << "Hace swap D_U" << endl;
            swap(vec[hoja], vec[hoja / 2]);
            Recuperar_D_U(hoja / 2);
        }
    }
}

template<class T>
void MonticuloV<T>::Recuperar_U_D(int hoja)
{
    //cout << "Entra Recuperar_U_D" << endl;
    if (2 * hoja < last && vec[2 * hoja]->Existe() && vec[(2 * hoja) + 1]->Existe())
    {
        //cout << "Primer control correcto U_D 2nodo" << endl;
        if (vec[2 * hoja]->Dato() < vec[(2 * hoja) + 1]->Dato())
        {
            if (vec[2 * hoja]->Dato() < vec[hoja]->Dato())
            {
                //cout << "1 Hace swap U_D" << endl;
                swap(vec[2 * hoja], vec[hoja]);
                Recuperar_U_D(2 * hoja);
            }
        }
        else
        {
            if (vec[(2 * hoja) + 1]->Dato() < vec[hoja]->Dato())
            {
                //cout << "2 Hace swap U_D" << endl;
                swap(vec[(2 * hoja) + 1], vec[hoja]);
                Recuperar_U_D((2 * hoja) + 1);
            }
        }
    }
    else if (vec[2 * hoja]->Existe())
    {
        //cout << "Primer control correcto U_D  1nodo" << endl;
        if (vec[2 * hoja]->Dato() < vec[hoja]->Dato())
        {
            //cout << "3 Hace swap U_D" << endl;
            swap(vec[2 * hoja], vec[hoja]);
        }
    }
}

template<class T>
T MonticuloV<T>::ELIMINAR()
{
    T res;
    if (last == 0)
    {
        throw runtime_error("Montículo vacío");
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
inline void MonticuloV<T>::mostrarcolaP()
{
        cout << "Contenido de la cola de prioridad:\n";
        for (int i = 1; i <= last; i++) // Empieza en 1 porque el índice 0 no se usa
        {
            std::cout << "Nodo " << i << ": ";
            if constexpr (std::is_same<T, std::pair<int, std::string>>::value)
            {
                // Si los elementos son pair<int, string>, muestra ambos componentes
                std::cout << "{ Clave: " << vec[i]->Dato().first
                    << ", Valor: " << vec[i]->Dato().second << " }";
            }
            else
            {
                // Si no es pair<int, string>, simplemente muestra el dato
                std::cout << vec[i]->Dato();
            }
            std::cout << "\n";
        }
}
