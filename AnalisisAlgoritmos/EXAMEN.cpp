#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    long long ans = -1e9;
    int i = 0;
    long long sum = 0;
    int count = 0;
    while (i < n) 
    {
        sum += x[i];
        count++;
        if (count >= a) 
        {
            if (count > b)
            {
                count = 0;
                sum = 0;
                i = i - b + 1;
            }
            else
            {
                ans = max(ans, sum);
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    /*
    -1 3 -2 5 3 -5 2 2
    
    a 2
    b 3
    2 [0,1]
    0 [0,1,2]


    */

    cout << ans << "\n";
}
/*
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() 
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> x(n), prefix(n + 1, 0); // x vector real, prefix vector de uno siguiente

    for (int i = 0; i < n; i++) 
    {
        cin >> x[i];
        prefix[i + 1] = prefix[i] + x[i];

    }

    multiset<long long> s; // set pero con elementos repetidos por repeticion de sumas obtenidas
    long long ans = -1e18;

    for (int i = a; i <= n; i++) 
    {
        // agregar nuevo candidato
        s.insert(prefix[i - a]);

        // eliminar fuera de rango
        if (i - b - 1 >= 0) 
        {
            s.erase(s.find(prefix[i - b - 1]));
        }

        // mejor resultado
        ans = max(ans, prefix[i] - *s.begin());
    }
    cout << ans << '\n';
}


EJERCICIO C

#include <iostream>
using namespace std;
int main()
{

int n;
cin >> n;

long long x;
cin >> x;

long long actual = x;
long long mejor = x;

for (int i = 1; i < n; i++) {
    cin >> x;

    actual = max(x, actual + x);
    mejor = max(mejor, actual);
}

cout << mejor << '\n';
}


EJERCICIO B

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    unordered_map<long long, int> pos;
    pos.reserve(n); 

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        long long complemento = x - num;

        auto it = pos.find(complemento); 
        if (it != pos.end()) {
            cout << it->second + 1 << " " << i + 1 << '\n';
            return 0;
        }

        pos[num] = i;
    }

    cout << "IMPOSSIBLE\n";
}

EJERCICIO A

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int maximo = 1;
    int actual = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            actual++;
            maximo = max(maximo, actual);
        } else {
            actual = 1;
        }
    }

    cout << maximo << endl;
    return 0;
}
*/