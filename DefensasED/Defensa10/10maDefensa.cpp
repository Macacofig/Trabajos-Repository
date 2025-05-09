
#include "Monticulo.h"
#include "MonticuloV.h"
void menu()
{
    cout << " 1. ELIMINAR PALABRA MENOR" << endl;
    cout << " 2. MOSTRAR PALABRAS INGRESADAS" << endl;
    cout << " 3. LEER ARCHIVO Texto Mediano" << endl;
    cout << " 4. Ordenar" << endl;
    cout << " 5. SALIR" << endl;
}
int main()
{
    /*
    Monticulo<string> mons;
    Nodo<string>** nod;
    int last1 = 1;
    int des;
    do {
        cout << endl;
        menu();
        cout << "Ingrese una opcion:";
        cin >> des;
        switch (des)
        {
        case 1:
            cout << " 3. ELIMINAR PALABRA MENOR" << endl;
            cout << "Palbra eliminada: " << mons.ELIMINARS() << endl;
            break;
        case 2:
            cout << " 2. MOSTRAR PALABRAS INGRESADAS" << endl;
            mons.MOSTRAR();
            break;
        case 3:
            cout << " 3. LEER ARCHIVO Texto Mediano" << endl;
            mons.LEERARCHIVO("TextoMediano.txt");
            break;
        case 4:
            cout << " 4. Ordenar" << endl;
            nod = mons.sort(last1);
            for (int i = 1; i <= last1; i++)
            {
                cout << nod[i]->Dato() << endl;
            }
            break;
        case 5:
            cout << " 9. SALIR" << endl;
            break;
        }
    } while (des != 5);
    
     */
    MonticuloV<string> mons2;
    mons2.sort("cads.txt");
    return 0;
}
