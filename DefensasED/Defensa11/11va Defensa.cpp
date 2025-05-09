#include "Grafo.h"
void menu()
{
    cout << "1. Leer Archivo" << endl;
    cout << "2. Insertar Arista" << endl;
    cout << "3. Mostrar Grafo" << endl;
    cout << "4. Amplitud" << endl;
    cout << "5. Profundidad" << endl;
    cout << "6. Salir" << endl;
    cout << "7. Reiniciar" << endl;
    cout << "8. Defensa" << endl;
}
int main()
{
    Grafo<int> g;
    int des;
    int el1, el2;
    string nom;
    do {
        cout << endl;
        menu();
        cout << "Ingrese una opcion:";
        cin >> des;
        switch (des)
        {
        case 1:
            cout << "1. Leer Archivo" << endl;
            cout << "Ingresar nombre del archivo:";
            cin >> nom;
            g.LeerArchivo(nom);
            break;
        case 2:
            cout << "2. Insertar Arista" << endl;
            cout << "Ingrese 1er dato:";
            cin >> el1;
            cout << "Ingrese 2do dato:";
            cin >> el2;
            g.InsertarArista(el1, el2);
            break;
        case 3:
            cout << "3. Mostrar Grafo" << endl;
            g.MostrarGrafo();
            break;
        case 4:
            cout << "4. Amplitud" << endl;
            cout << "Elija un origen: ";
            cin >> el1;
            cout << "Elija un destino: ";
            cin >> el2;
            cout << "Buscar Amplitud " << g.Amplitud(el1, el2);
            break;
        case 5:
            cout << "5. Profundidad" << endl;
            cout << "Elija un origen: ";
            cin >> el1;
            cout << "Elija un destino: ";
            cin >> el2;
            cout << "Buscar Profundidad " << g.Profundidad(el1, el2);
            break;
        case 6:
            cout << "6. Salir" << endl;
            break;
        case 7:
            cout << "7. Reiniciar" << endl;
            g.IniciarPadreMarca();
            break;
        case 8:
            cout << "8. Defensa" << endl;
            g.MostrarCamino(el1,el2);
            break;
        }
    } while (des != 6);
    return 0;
}
