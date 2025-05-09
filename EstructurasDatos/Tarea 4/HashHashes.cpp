
#include "HashSimple.h"

void menu()
{
    cout << endl;
    cout << "1. Insertar palabra" << endl;//check
    cout << "2. Eliminar palabra" << endl;//check
    cout << "3. Buscar palabra" << endl;//check
    cout << "4. Mostrar la Hash de Hash" << endl;//check
    cout << "5. Leer de Archivo" << endl;
    cout << "6. Salir" << endl;//check
    cout << endl;
}
int main()
{
    HashSimple<string> hs;

    Hash<string>aux;
    int op;
    string palabra;
    
    do {
        menu();
        cout << "Ingresa una opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Insertar palabra" << endl;
            cout << "Ingrese la palabra a insertar: ";
            cin >> palabra;
            cout << "Verificacion: " << hs.InsertWord(palabra) << endl;
            break;
        case 2:
            cout << "Eliminar palabra" << endl;
            cout << "Ingrese la palabra a eliminar: ";
            cin >> palabra;
            cout << "Verificacion: " << hs.DeleteWord(palabra) << endl;
            break;
        case 3:
            cout << "Buscar palabra" << endl;
            cout << "Ingrese la palabra a buscar: ";
            cin >> palabra;
            if (hs.SearchWord(palabra) == -1)
            {
                cout << "Palabra no encontrada" << endl;
            }
            else
            {
                cout << "Palabra encontrada en HashSimple:" << hs.HSFunction(palabra) << ", Hash:" << aux.HFunction(palabra) << endl;
            }
            break;
        case 4:
            cout << "Mostrar la Hash de Hash" << endl;
            hs.Show();
                break;
        case 5:
            cout << "Leer de Archivo" << endl;
            cout << "Ingrese el nombre del archivo: ";
            cin >> palabra;
            cout << "Verificacion: " << hs.InsertArchivo(palabra);
            break;
        case 6:
            cout << "Programa finalizado";
            break;
        }
    } while (op != 6);
}