
#include "HashSimple.h"
#include "timer.h"
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
    timer r1;
    r1.start();
    hs.InsertArchivo("cien anos de soledad.txt");
    r1.stop();
    cout << "tiempo de ingreso: " << r1 << endl;
    hs.Analyze();

}