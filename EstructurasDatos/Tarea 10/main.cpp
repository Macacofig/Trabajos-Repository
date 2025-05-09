#include "Monticulo.h"
void menu()
{
    cout << " 1. INSERTAR al Heap" << endl;
    cout << " 2. ELIMINAR MENOR" << endl;
    cout << " 3. ELIMINAR PALABRA MENOR" << endl; 
    cout << " 4. MOSTRAR NUMEROS" << endl; 
    cout << " 5. MOSTRAR PALABRAS INGRESADAS" << endl;
    cout << " 6. LEER ARCHIVO Texto Mediano" << endl;
    cout << " 7. SALIR" << endl;
}
int main()
{
    Monticulo<int> mon;
    Monticulo<string> mons;
    int des;
    int el;
    do {
        cout << endl;
        menu();
        cout << "Ingrese una opcion:";
        cin >> des;
        switch (des)
        {
        case 1:
            cout << " 1. INSERTAR" << endl;
            cout << "Ingresar numero:";
            cin >> el;
            mon.INSERTAR(el);
            break;
        case 2:
            cout << " 2. ELIMINAR MENOR" << endl;
            cout << "Numero eliminado: " << mon.ELIMINAR() << endl;
            break;
        case 3:
            cout << " 3. ELIMINAR PALABRA MENOR" << endl;
            cout << "Palbra eliminada: " << mons.ELIMINARS() << endl;
            break;
        case 4:
            cout << " 4. MOSTRAR NUMEROS" << endl;
            mon.MOSTRAR();
            break;
        case 5:
            cout << " 5. MOSTRAR PALABRAS INGRESADAS" << endl;
            mons.MOSTRAR();
            break;
        case 6:
            cout << " 6. LEER ARCHIVO Texto Mediano" << endl;
            mons.LEERARCHIVO("TextoMediano.txt");
            break;
        case 7:
            cout << "Programa finalizado" << endl;
            break;
        }
    } while (des != 7);
    return 0;
}