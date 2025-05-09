#include "GrafoPeso.h"

#include <iostream>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    GrafoPeso<string> g;
    g.LeerArchivo();
    int min = 1000000;
    unordered_map<string, Nodo<string>> gg = g.getgrafo();
    g.mostrar(gg);
    int limite = static_cast<int>(g.getgrafo().size() * g.getgrafo().size() * log10(g.getgrafo().size()));
    for (int i = 1; i <= limite;i++)
    {
        gg = g.getgrafo();
        g.CorteMin(gg);
        //g.mostrar(gg);
        cout << "cantidad aristas: " << g.contarAristas(gg) <<endl;
        if (g.contarAristas(gg) < min)
        {
            min = g.contarAristas(gg);
        }
    }
    
    cout << "El corte minimo final es : " << min;
    
}
