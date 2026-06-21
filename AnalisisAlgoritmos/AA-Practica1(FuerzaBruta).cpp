#include <iostream>
#include <vector>
#include <algorithm>

/*
Mateo Figueroa
Nataly Ramirez
Ostin Colque
*/

/* EJERCICIO 1*/

void SubCadenaEnCadena() {
    std::string T, P;
    std::cin >> T >> P;

    bool found = false;

    for (int i = 0; i <= T.size() - P.size(); i++) {
        bool match = true;

        for (int j = 0; j < P.size(); j++) {
            if (T[i + j] != P[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            std::cout << i << " ";
            found = true;
        }
    }

    if (!found) std::cout << "NO ENCONTRADO";

}

/* EJERCICIO 2*/

void SumaSunconjunto() {
    int n, S;
    std::cin >> n >> S;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    std::vector<std::vector<int>> subconjuntos = { {} };
    std::vector<std::vector<int>> nuevos;
    std::vector<int> copia;
    // generar todos los subconjuntos
    for (int num : arr) {
        

        for (auto sub : subconjuntos) {
            copia = sub;
            copia.push_back(num);
            nuevos.push_back(copia);
        }

        subconjuntos.insert(subconjuntos.end(), nuevos.begin(), nuevos.end());
    }

    // buscar suma
    for (auto sub : subconjuntos) {
        int suma = 0;
        for (int x : sub) suma += x;

        if (suma == S) {
            std::cout << "SI ";
            for (int x : sub) std::cout << x << " ";
            return;
        }
    }

    std::cout << "NO";
}

/* EJERCICIO 3*/

void generar(const std::string& cadena, std::string actual, std::vector<bool>& usado, std::vector<std::string>& resultado) {
    if (actual.size() == cadena.size()) {
        resultado.push_back(actual);
        return;
    }

    for (int i = 0; i < cadena.size(); i++) {
        if (!usado[i]) {
            usado[i] = true;

            generar(cadena, actual + cadena[i], usado, resultado);

            usado[i] = false;
        }
    }
}

std::vector<std::string> combinatoria(const std::string& cadena) {
    std::vector<std::string> resultado;
    std::vector<bool> usado(cadena.size(), false);

    generar(cadena, "", usado, resultado);

    return resultado;
}

void Combinaciones()
{
    std::string cadena = "1234";

    std::vector<std::string> resultado = combinatoria(cadena);

    for (const std::string& s : resultado) {
        std::cout << s << std::endl;
    }

    std::cout << "Total: " << resultado.size() << std::endl;
}

/* EJERCICIO 4*/
std::vector<std::vector<int>> resultado4;

void bt(int idx, int suma, int target, std::vector<int>& nums, std::vector<int>& actual) {
    if (suma == target) {
        resultado4.push_back(actual);
        return;
    }

    if (suma > target) return;

    for (int i = idx; i < nums.size(); i++) {
        actual.push_back(nums[i]);
        bt(i, suma + nums[i], target, nums, actual);
        actual.pop_back();
    }
}

void Combinaciones_coin_change()
{
    
    int target;
    std::cin >> target;

    std::vector<int> nums;
    int x;
    while (std::cin >> x) nums.push_back(x);

    std::sort(nums.begin(), nums.end());

    std::vector<int> actual;
    bt(0, 0, target, nums, actual);

    std::cout << resultado4.size() << std::endl;

    for (auto& comb : resultado4) {
        for (int x : comb) std::cout << x << " ";
        std::cout << std::endl;
    }
}

int main() {
    return 0;
}


/*
actual = "" : 0
cadena = 123 : 3
usado = [false,false,false]
resultado = []

i = 0

recur 1
actual = "1" : 1
usado = [true,false,false]

    i = 0 → usado → skip

    i = 1

    recur 2
    actual = "12" : 2
    usado = [true,true,false]

        i = 0 → usado → skip
        i = 1 → usado → skip

        i = 2

        recur 3
        actual = "123" : 3
        usado = [true,true,true]
        resultado = ["123"]

        return (backtrack)
        usado = [true,true,false]

    fin for

    return (backtrack)
    usado = [true,false,false]

    i = 2

    recur 2
    actual = "13" : 2
    usado = [true,false,true]

        i = 0 → usado → skip

        i = 1

        recur 3
        actual = "132" : 3
        usado = [true,true,true]
        resultado = ["123","132"]

        return (backtrack)
        usado = [true,false,true]

        i = 2 → usado → skip

    fin for

    return (backtrack)
    usado = [false,false,false]

--------------------------------------------------

i = 1

recur 1
actual = "2" : 1
usado = [false,true,false]

    i = 0

    recur 2
    actual = "21" : 2
    usado = [true,true,false]

        i = 0 → usado → skip
        i = 1 → usado → skip

        i = 2

        recur 3
        actual = "213" : 3
        usado = [true,true,true]
        resultado = ["123","132","213"]

        return
        usado = [true,true,false]

    return
    usado = [false,true,false]

    i = 1 → usado → skip

    i = 2

    recur 2
    actual = "23" : 2
    usado = [false,true,true]

        i = 0

        recur 3
        actual = "231" : 3
        usado = [true,true,true]
        resultado = ["123","132","213","231"]

        return
        usado = [false,true,true]

    return
    usado = [false,false,false]

--------------------------------------------------

i = 2

recur 1
actual = "3" : 1
usado = [false,false,true]

    i = 0

    recur 2
    actual = "31" : 2
    usado = [true,false,true]

        i = 1

        recur 3
        actual = "312" : 3
        usado = [true,true,true]
        resultado = ["123","132","213","231","312"]

        return
        usado = [true,false,true]

    return
    usado = [false,false,true]

    i = 1

    recur 2
    actual = "32" : 2
    usado = [false,true,true]

        i = 0

        recur 3
        actual = "321" : 3
        usado = [true,true,true]
        resultado = ["123","132","213","231","312","321"]

        return
        usado = [false,true,true]

    return
    usado = [false,false,false]
*/

