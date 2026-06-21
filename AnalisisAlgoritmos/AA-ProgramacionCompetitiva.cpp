/*
#include <iostream>
using namespace std;

int mejorInicio, mejorLongitud;

void expandir(const string& s, int izquierda, int derecha, bool permitirCompleto)
{
    while (izquierda >= 0 && derecha < s.size() && s[izquierda] == s[derecha])
    {
        int longitud = derecha - izquierda + 1;

        if ((permitirCompleto || longitud != s.size()) && 
            (longitud > mejorLongitud || (longitud == mejorLongitud && izquierda < mejorInicio)))
        {
            mejorInicio = izquierda;
            mejorLongitud = longitud;
        }

        izquierda--;
        derecha++;
    }
}

string encontrarMayor(const string& cadena, bool permitirCompleto)
{
    mejorInicio = 0;
    mejorLongitud = 0;

    for (int i = 0; i < cadena.size(); i++)
    {
        expandir(cadena, i, i, permitirCompleto);
        expandir(cadena, i, i + 1, permitirCompleto);
    }

    return cadena.substr(mejorInicio, mejorLongitud);
}

int main()
{
    string cadena;
    cin >> cadena;

    string mejor = encontrarMayor(cadena, false);

    cout << mejor << endl;

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane 1D
int kadane(const vector<int>& arr) {
    int max_actual = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        max_actual = max(arr[i], max_actual + arr[i]);
        max_global = max(max_global, max_actual);
    }

    return max_global;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matriz(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matriz[i][j];
        }
    }

    int max_suma = INT_MIN;

    // Fijar fila superior
    for (int top = 0; top < N; top++) {
        vector<int> temp(N, 0);

        // Expandir hacia abajo
        for (int bottom = top; bottom < N; bottom++) {

            for (int col = 0; col < N; col++) {
                temp[col] += matriz[bottom][col];
            }

            // Aplicar Kadane
            int suma_actual = kadane(temp);
            max_suma = max(max_suma, suma_actual);
        }
    }

    cout << max_suma << endl;

    return 0;
}