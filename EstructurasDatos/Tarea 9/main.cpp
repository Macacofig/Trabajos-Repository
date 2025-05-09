#include "AVT.h"

void menu()
{
    cout << "1. Insertar nueva Palabra " << endl;
    cout << "2. Buscar una Palabra " << endl;
    cout << "3. Mostrar palabras que empiecen con(Como en el celular) " << endl;
    cout << "4. Salir" << endl;
}
int main()
{
    AVT<string> avt;
    string elem;
    int des;
    do
    {
        cout << endl;
        menu();
        cout << "Elije una opcion: ";
        cin >> des;
        switch (des)
        {
        case 1:
            cout << "1. INSERTAR " << endl;
            cout << "Ingrese el dato: ";
            cin >> elem;
            avt.Insertar(elem, avt.Raiz());
            break;
        case 2:
            cout << " 2. BUSCAR " << endl;
            cout << " Ingrese la palabra a buscar: ";
            cin >> elem;
            cout << avt.Buscar(elem, avt.Raiz()) << endl;
            break;
        case 3:
            cout << " 3. MOSTRAR DESDE PREFIJO " << endl;
            cout << " Ingresar prefijo: ";
            cin >> elem;
            cout << "Palabras encontradas: " << endl;
            avt.Mostrar(elem, avt.Raiz());
            break;
        case 4:
            cout << " 4. Salir " << endl;
            cout << "Programa finalizado" << endl;
            break;
        }
    } while (des != 4);
    return 0;
}