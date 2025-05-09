#include "GrafoPeso.h"
void menu()
{
    cout << "1. Leer Archivo" << endl;
    cout << "2. Insertar Arista" << endl;
    cout << "3. Mostrar Grafo" << endl;
    cout << "4. Kruskal" << endl;
    cout << "5. Mostrar AE" << endl;
    cout << "6. Defensa " << endl;
    cout << "7. Salir" << endl;
}
int main()
{
    GrafoPeso g;
    int des;
    string el1, el2;
    int tam;
    string nom;
    vector<pair<string, string>> arbolExpansion;
    int totalCosto;
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
            cout << "Ingrese 1er dato: ";
            cin >> el1;
            cout << "Ingrese 2do dato: ";
            cin >> el2;
            cout << "Ingrese costo: ";
            cin >> tam;
            g.Insertar(el1, el2, tam);
            break;
        case 3:
            cout << "3. Mostrar Grafo" << endl;
            g.mostrar();
            break;
        case 4:
            cout << "4. Kruskal" << endl;
            g.kruskal(arbolExpansion, totalCosto);
            break;
        case 5:
            cout << "5. Mostrar AE" << endl;
            g.mostrarAE(arbolExpansion, totalCosto);
            break;
        case 6:
            cout << "6. Defensa" << endl;
            break;
        case 7:
            cout << "7.Salir";
            break;
        }
    } while (des != 6);
    return 0;
}