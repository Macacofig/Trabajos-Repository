#include "ArbolRojoNegro.h"

void menu()
{
    cout << "1. INSERTAR " << endl;
    cout << "2. Rotar Izquierda " << endl;
    cout << "3. Rotar Derecho " << endl;
    cout << "4. CONTAR NODOS " << endl;
    cout << "5. CALCULAR ALTURA " << endl;
    cout << "6. MOSTRAR IN ORDER " << endl;
    cout << "7. MOSTRAR PRE ORDER " << endl;
    cout << "8. MOSTRAR POST ORDER " << endl;
    cout << "9. Buscar " << endl;
    cout << "10. Eliminar TODO " << endl;
    cout << "11. Insertar Diccionario " << endl;
    cout << "12. Salir " << endl;
    cout << "13. CUIDADO mostrar diccionario" << endl;
}
int main()
{
    ArbolRojoNegro<int> arn;
    ArbolRojoNegro<string> arns;
    string c = "";
    string p = "";
    string l = "";
    int des;
    int elem; 
    Nodo<int>* aux = NULL;
    do
    {
        cout << endl;
        menu();
        cout << "Elije una opcion: ";
        cin >> des;
        switch (des)
        {
        case 1:
            c = "";
            p = "";
            l = "";
            cout << "1. INSERTAR " << endl;
            cout << "Ingrese el dato: ";
            cin >> elem;
            arn.insert(elem, arn.getRaizRef(),c,l,p);
            cout << "La raiz actual:"<< arn.getRaiz()->getDato() << endl; 
            break;
        case 2:
            cout << "2. Rotar Izquierda " << endl;
            cout << "Se realiza automaticamente al insertar un dato" << endl;
            break;
        case 3:
            cout << "3. Rotar Derecho " << endl;
            cout << "Se realiza automaticamente al insertar un dato" << endl; 
            break;
        case 4:
            cout << "4. CONTAR NODOS " << endl;
            cout << "La cantidad de nodos es: " << arn.NodoCount(arn.getRaiz()) << endl;
            break;
        case 5:
            cout << "5. CALCULAR ALTURA " << endl;
            cout << "La altura del arbol es: " << arn.Altura(arn.getRaiz()) << endl;
            break;
        case 6:
            cout << "6. MOSTRAR IN ORDER " << endl;
            cout << arn.getRaiz()->getDato() << endl;
            arn.ShowInOrder(arn.getRaiz());
            break;
        case 7:
            cout << "7. MOSTRAR PRE ORDER " << endl;
            cout << arn.getRaiz()->getDato() << endl;
            arn.ShowPreOrder(arn.getRaiz());
            break;
        case 8:
            cout << "8. MOSTRAR POST ORDER " << endl;
            cout << arn.getRaiz()->getDato() << endl;
            arn.ShowPostOrder(arn.getRaiz());
            break;
        case 9:
            cout << "9. Buscar " << endl;
            cout << "Ingrese el dato a buscar: ";
            cin >> elem;
            aux = arn.Buscar(elem, arn.getRaiz());
            break;
        case 10:
            cout << "10. Eliminar TODO " << endl;
            arn.DeleteAll(0, arn.getRaizRef(), 1);
            break;
        case 11:
            cout << "11. Insertar Diccionario " << endl;
            arns.InsertDictionary("Diccionario.txt");
            break;
        case 12:
            cout << " Programa Finalizado" << endl;
            break;
        case 13:
            cout << " 13. CUIDADO mostrar diccionario" << endl;
            arns.ShowInOrder(arns.getRaiz());
            break;
        }
    } while (des != 12);
    return 0;
}