#include "AVL.h"
#include <cstdlib>
#include <time.h>

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
	cout << "13. Defensa" << endl;
    cout << "14. Salir" << endl;
}
int main()
{
    AVL<string> arns;
    AVL<int> avl; 
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
            avl.insert(elem, avl.getRaizRef(), c);
            cout << "La raiz actual:" << avl.getRaiz()->Dato() << endl;
            break;
        case 2:
            cout << " 2. CONTAR NODOS " << endl;
            cout << " Nodos: " << avl.NodoCount(avl.getRaiz()) << endl;
            break;
        case 3:
            cout << " 3. CALCULAR ALTURA " << endl;
            cout << " Altura avl int: " << avl.Altura(avl.getRaiz()) << endl;
            cout << " Altura avl string: " << arns.Altura(arns.getRaiz()) << endl;

            break;
        case 4:
            cout << " 4. MOSTRAR IN ORDER " << endl;
            cout << avl.getRaiz()->Dato() << endl;
            avl.ShowInOrder(avl.getRaiz());
            break;
        case 5:
            cout << " 5. MOSTRAR PRE ORDER " << endl;
            cout << avl.getRaiz()->Dato() << endl;
            avl.ShowPreOrder(avl.getRaiz());
            break;
        case 6:
            cout << " 6. MOSTRAR POST ORDER " << endl;
            cout << avl.getRaiz()->Dato() << endl;
            avl.ShowPostOrder(avl.getRaiz());
            break;
        case 7:
            cout << " 7. CONTAR HOJAS DEL ÁRBOL " << endl;
            cout << "Hojas: " << avl.countHojas(avl.getRaiz()) << endl;
            break;
        case 8:
            cout << " 8. POR NIVELES " << endl;
            avl.MostrarNiveles(avl.getRaiz());
            break;
        case 9:
            cout << " 9. Buscar Mayor " << endl;
            aux = avl.BuscarMayor(avl.getRaiz());
            cout << "EL DATO MAYOR: " << aux->Dato() << endl;
            break;
        case 10:
            cout << " 10. Buscar menor " << endl;
            aux = avl.BuscarMenor(avl.getRaiz());
            cout << "EL DATO MENOR: " << aux->Dato() << endl;
            break;
        case 11:
            cout << " 11. Eliminar TODO " << endl;
            avl.DeleteAll(0, avl.getRaizRef(), 1);
            break;
        case 12:
            cout << " 12. Insertar Diccionario" << endl;
            arns.InsertDictionary("Diccionario.txt");
            break;
        case 13:
            bool res;
            srand(time(NULL)); 
            for (int i = 0; i < 50000; i++)
            {
                c = ""; 
                avl.insert(1 + (rand() % (50000)), avl.getRaizRef(), c); 
            }
            res = avl.ControlAlturas(avl.getRaiz()); 
            //res = avl.controlalturas(avl.getRaiz()->getLeft(), avl.getRaiz()->getRight());
            if (res)
            {
                cout << res << endl;
                cout << "Alturas correctas" << endl;
            }
            else
            {
                cout << res << endl;
                cout << "Alturas no correctas" << endl;
            }
            break;
        case 14:
            cout << " 14. Programa Finalizado" << endl;
            break;
        }
    } while (des != 14);
    return 0;
}
