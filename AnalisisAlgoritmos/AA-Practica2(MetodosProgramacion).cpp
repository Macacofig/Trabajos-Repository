
/*

entrada U = cadena de valores positivos, ordenados (ascendente)
objetivo = entero, tiene que ser alcanzado por (sumas,restas,multiplicaciones, sin operacion)

str u = ""
vector<int> = numeros = convertirCadena(u)
vector<vector<int>> = combinaciones



function (combinaciones,numeros,objetivo,vecsuma,vecresta,vecmul,suma,resta,mult,ind)
{


6
1 2 3


1 + 2 = 3
    1 + 2 + 3
    1 + 2 - 3
    1 + 2 * 3
1 - 2 = -1
    1 - 2 + 3
    1 - 2 - 3
    1 - 2 * 3
1 * 2 = 2
    1 * 2 + 3
    1 * 2 - 3
    1 * 2 * 3

1 + 3
1 - 3
1 * 3

2 + 3
2 - 3
2 * 3



*/

#include <iostream>
#include <vector>

std::vector<int> convertir(std::string numeros) {
	std::vector<int> resultado = {};

	for (int i = 0; i < numeros.size(); i++) {
		resultado.push_back(numeros[i] - '0');
	}
	return resultado;
}

void Combinaciones(
    std::vector<std::vector<int>>& combinaciones,
    std::vector<int>& numeros,
    int objetivo,
    std::vector<int>& actual,
    int resultado,
    int ind
)
{
    if (ind == numeros.size())
    {
        if (resultado == objetivo)
        {
            combinaciones.push_back(actual);
        }
        return;
    }

    for (int i = ind; i < numeros.size(); i++)
    {
        int num = numeros[i];

        if (actual.empty())
        {
            actual.push_back(num);
            Combinaciones(combinaciones, numeros, objetivo, actual, num, i + 1);
            actual.pop_back();
        }
        else
        {
            // +
            actual.push_back(num);
            Combinaciones(combinaciones, numeros, objetivo, actual,
                resultado + num,
                i + 1);
            actual.pop_back();

            // -
            actual.push_back(num);
            Combinaciones(combinaciones, numeros, objetivo, actual,
                resultado - num,
                i + 1);
            actual.pop_back();

            // *
            actual.push_back(num);
            Combinaciones(combinaciones, numeros, objetivo, actual,
                resultado * num,
                i + 1);
            actual.pop_back();
        }
    }
}
int main()
{
    std::vector<std::vector<int>> combinaciones;
    std::vector<int> numeros = { 1,2,3 };
    int objetivo = 6;
    std::vector<int> actual;

    Combinaciones(combinaciones, numeros, objetivo, actual, 0, 0);

    std::cout << combinaciones.size() << std::endl;

    /*
    for (const auto combinacion : combinaciones)
    {
        for (const auto numero : combinacion)
        {
            std::cout << numero << " ";
        }
        std::cout << std::endl;
    }
    */
}
