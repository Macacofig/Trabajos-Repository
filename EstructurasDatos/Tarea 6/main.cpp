#include "ArbolBinarioBusqueda.h"
void menu()
{
	cout << "1. INSERTAR(detalle&*)" << endl;
	cout << "2. CONTAR NODOS" << endl;
	cout << "3. CALCULAR ALTURA" << endl;
	cout << "4. MOSTRAR IN ORDER" << endl;
	cout << "5. MOSTRAR PRE ORDER" << endl;
	cout << "6. MOSTRAR POST ORDER" << endl;
	cout << "7. BUSCAR" << endl;
	cout << "8. MENOR" << endl;
	cout << "9. MAYOR" << endl;
	cout << "10. Eliminar 1 Elemento" << endl;
	cout << "11. Salir" << endl;

}
int main()
{
	ArbolBinarioBusqueda<int> a;
	int des;
	int elem; 
	Nodo<int>* res;
	do 
	{
		cout << endl;
		menu();
		cout << "Elija una opcion: ";
		cin >> des;
		switch (des)
		{
		case 1:
			cout << "Insertar numero: ";
			cin >> elem;
			a.insertar(elem, a.getRaizRef());

			cout << "Se ingreso el dato: " << a.getRaiz()->getDato() << endl;
			break;
		case 2:
			cout << "Contar Nodos" << endl;
			cout << "cantidad de nodos: " << a.contarNodo(a.getRaiz()) << endl;
			break;
		case 3:
			cout << "Calcular Altura" << endl;
			cout << "altura del arbol: " << a.Altura(a.getRaiz()) << endl;
			break;
		case 4:
			cout << "Mostrar INORDER" << endl;
			a.ShowInOrder(a.getRaiz());
			cout << endl;
			break;
		case 5:
			cout << "Mostrar PREORDER" << endl; 
			a.ShowPreOrder(a.getRaiz());
			cout << endl;
			break;
		case 6:
			cout << "Mostrar POSTORDER" << endl; 
			a.ShowPostOrder(a.getRaiz());
			cout << endl;
			break;
		case 7:
			cout << "Elemento a buscar: ";
			cin >> elem;
			res = a.Buscar(elem, a.getRaiz());
			if (res == NULL)
			{
				cout << "Elemento no encontrado" << endl;
			}
			else
			{
				cout << "Elemento encontrado" << endl;
			}
			break;
		case 8:
			cout << "Valor menor" << endl;
			res = a.menor(a.getRaiz());
			cout << "El valor menor es: " << res->getDato() << endl;
			break;
		case 9:
			cout << "Valor mayor" << endl;
			res = a.Mayor(a.getRaiz());
			cout << "El valor mayor es: " << res->getDato() << endl;
			break;
		case 10:
			cout << "Elemento a eliminar: ";
			cin >> elem;
			cout << "Verificacion de eliminacion: " << a.eliminar(elem, a.getRaiz()) << endl;
			break;
		case 11:
			cout << "Programa finalziado";
			break;
		}
	} while (des != 11);
}