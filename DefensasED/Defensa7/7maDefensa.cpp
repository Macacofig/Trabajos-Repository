#include <map>
#include <set>
#include <cstdlib>
#include <time.h>
#include "timer.h"
#include "ArbolRojoNegro.h"
int main()
{
    ArbolRojoNegro<string> arb;
    
    arb.InsertDictionary("Diccionario.txt");
    cout << "Cantidad nodos: " << arb.NodoCount(arb.getRaiz()) << endl;
    cout << "Altura: " << arb.Altura(arb.getRaiz());
    /*
    srand(time(NULL));
    string c = "";
    string p = "";
    string l = "";

    ArbolRojoNegro< int > arbolito;
    map< int, int > mapita;
    set< int > setsito;
    timer t1, t2, t3;
    t1.start();
    for (int i = 0; i < 100000; i++)
    {
        arbolito.insert(1 + rand() % (100000),arbolito.getRaizRef(),c,l,p);
    }
    t1.stop();
    t2.start();
    for (int i = 0; i < 100000; i++)
    {
        mapita[1 + rand() % (100000)] = 1 + rand() % (100000);
    }
    t2.stop(); 
    t3.start();
    for (int i = 0; i < 100000; i++)
    {
        setsito.insert(1 + rand() % (100000));
    }
    t3.stop();
    cout << "tiempo en ArbolRojoNegro: " << t1 << " y la altura ARN: " << arbolito.Altura(arbolito.getRaiz()) << endl;
    cout << "tiempo en map: " << t2 << " y el tamanio: " << mapita.size() << endl;
    cout << "tiempo en set: " << t3 << " y el tamanioo: " << setsito.size() << endl;
    */
    return 0;
}
