

/*
EJER7
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i; // índice original
    }

    sort(a.begin(), a.end());

    int maxDesplazamiento = 0;

    for (int i = 0; i < n; i++)
    {
        int desplazamiento = a[i].second - i;
        maxDesplazamiento = max(maxDesplazamiento, desplazamiento);
    }

    cout << maxDesplazamiento + 1 << endl;

    return 0;
}

EJER6
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> kids;
    for (int i = 1; i <= n; i++)
    {
        kids.push(i);
    }
    while (kids.size() > 1)
    {
        kids.push(kids.front());
        kids.pop();
        cout << kids.front() << " ";
        kids.pop();
    }
    cout << kids.front();

}

EJER5
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    set<int> numeros;
    int num;
    int n;
    cin >> n;
    while (cin >> num && n--)
    {
        numeros.insert(num);
        if (cin.peek() == '\n') break;
    }

    cout << numeros.size();
}

EJER4
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void generar_permutaciones(string s)
{
    sort(s.begin(), s.end());
    vector<string> resultado;
    do {
        resultado.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << resultado.size() << "\n";
    for (const string& permutation : resultado)
    {
        cout << permutation << "\n";
    }
}
int main()
{
    string entrada;
    if (cin >> entrada)
    {
        generar_permutaciones(entrada);
    }
}

EJER3
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        if (n == 0) break;

        queue<int> numeros;

        for (int i = 1; i <= n; i++)
        {
            numeros.push(i);
        }

        cout << "Discarded cards:";

        bool first = true;

        while (numeros.size() > 1)
        {
            if (first)
            {
                cout << " " << numeros.front();
                first = false;
            }
            else
            {
                cout << ", " << numeros.front();
            }

            numeros.pop();

            numeros.push(numeros.front());
            numeros.pop();
        }

        cout << "\nRemaining card: " << numeros.front() << "\n";
    }

    return 0;
}

EJER2
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<int, int> count;
    vector<int> orden;
    int num;

    while (cin >> num)
    {
        if (count[num] == 0)
        {
            orden.push_back(num); // guardar orden de aparición
        }
        count[num]++;
    }

    for (int x : orden)
    {
        cout << x << " " << count[x] << endl;
    }

    return 0;
}

EJER1

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // limpiar salto de línea

    string line;
    getline(cin, line); // consumir línea en blanco después de t

    while (t--) {
        map<string, int> count;
        int total = 0;

        while (getline(cin, line)) {
            if (line.empty()) break;
            count[line]++;
            total++;
        }

        for (auto& p : count) {
            double percentage = (p.second * 100.0) / total;
            cout << p.first << " ";
            cout << fixed << setprecision(4) << percentage << "\n";
        }

        if (t) cout << "\n";
    }

    return 0;
}*/

