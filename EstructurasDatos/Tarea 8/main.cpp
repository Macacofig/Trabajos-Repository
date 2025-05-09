
#include "AVL.h"

void menu()
{
    cout << "1. INSERTAR " << endl;
    cout << "2. CONTAR NODOS " << endl;
    cout << "3. CALCULAR ALTURA " << endl;
    cout << "4. MOSTRAR IN ORDER " << endl;
    cout << "5. MOSTRAR PRE ORDER " << endl;
    cout << "6. MOSTRAR POST ORDER " << endl;
    cout << "7. CONTAR HOJAS DEL ÁRBOL " << endl;
    cout << "8. MOSTRAR POR NIVELES " << endl;
    cout << "9. Buscar Mayor " << endl;
    cout << "10. Buscar menor " << endl;
    cout << "11. Eliminar TODO " << endl;
    cout << "12. Insertar Diccionario " << endl;
    cout << "13. Salir" << endl;
}
int main()
{
    AVL<int> arn;
    AVL<string> arns;
    string c = "";
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
            cout << "1. INSERTAR " << endl;
            cout << "Ingrese el dato: ";
            cin >> elem;
            arn.insert(elem, arn.getRaizRef(),c);
            cout << "La raiz actual:" << arn.getRaiz()->Dato() << endl;
            break;
        case 2:
            cout << " 2. CONTAR NODOS " << endl;
            cout << " Nodos: " << arn.NodoCount(arn.getRaiz()) << endl; 
            break;
        case 3:
            cout << " 3. CALCULAR ALTURA " << endl;
            cout << " Altura: " << arn.Altura(arn.getRaiz()) << endl; 
            break;
        case 4:
            cout << " 4. MOSTRAR IN ORDER " << endl;
            cout << arn.getRaiz()->Dato() << endl;
            arn.ShowInOrder(arn.getRaiz());
            break;
        case 5:
            cout << " 5. MOSTRAR PRE ORDER " << endl;
            cout << arn.getRaiz()->Dato() << endl;
            arn.ShowPreOrder(arn.getRaiz());
            break;
        case 6:
            cout << " 6. MOSTRAR POST ORDER " << endl;
            cout << arn.getRaiz()->Dato() << endl;
            arn.ShowPostOrder(arn.getRaiz());
            break;
        case 7:
            cout << " 7. CONTAR HOJAS DEL ÁRBOL " << endl;
            cout << "Hojas: " << arn.countHojas(arn.getRaiz()) << endl;
            break;
        case 8:
            cout << " 8. POR NIVELES " << endl;
            arn.MostrarNiveles(arn.getRaiz());
            break;
        case 9:
            cout << " 9. Buscar Mayor " << endl;
            aux = arn.BuscarMayor(arn.getRaiz());
            cout << "EL DATO MAYOR: " << aux->Dato() <<endl;
            break;
        case 10:
            cout << " 10. Buscar menor " << endl;
            aux = arn.BuscarMenor(arn.getRaiz());
            cout << "EL DATO MENOR: " << aux->Dato() << endl;
            break;
        case 11:
            cout << " 11. Eliminar TODO " << endl;
            arn.DeleteAll(0, arn.getRaizRef(), 1); 
            break;
        case 12:
            cout << " 12. Insertar Diccionario" << endl;
            arns.InsertDictionary("Diccionario.txt");
            break;
        case 13:
            cout << " 13. Programa Finalizado" << endl;
            break;
        }
    } while (des != 13);
    return 0;
}
