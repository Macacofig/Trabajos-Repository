#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

/*
MATEO GAEL FIGUEROA CHAVEZ
NATALY RAMIREZ MACHICADO
OSTIN COLQUE
*/

/* EJERCICIO 1*/

/* GEDDY
Logica :
Pos Inicial = 0
consumo = 1 litro por km

Inputs
Linea 1 : 3 enteros : distancia_total (kms), capacidad_tanque, numero_estaciones
LInea 2 : n posiciones_estaciones

OutPut
Linea 1: mumero min de paradas
Linea 2: posicones_estaciones (en orden de recorrido)
no hay paradas : -
imposible : -1

Restricciones : 1 al distancia_total -1

Objetivo llegar a D en la menor cantidad de paradas posibles

*/

bool comparar(int a, int b) //mayor a menor

{
	return a > b;
}
std::vector<int> ordenar(std::vector<int>estaciones)
{
	std::sort(estaciones.begin(), estaciones.end(), comparar);
	return estaciones;
}
std::vector<int> crearEstaciones(int n)
{
	std::vector<int> estaciones;
	int pos;
	for (int i = 0; i < n; i++)
	{
		std::cin >> pos;
		estaciones.push_back(pos);
	}
	return estaciones;
}

std::vector<int> recorrerAutopista(std::vector<int> estaciones, int distanciaTotal, int capacidadTanque)
{
	//inicializar
	std::vector<int> estacionesParar = {};
	int posActual = 0;
	//ordenar
	estaciones = ordenar(estaciones);
	//mientras
	if (posActual + capacidadTanque < distanciaTotal)
	{
		while (!estaciones.empty() && posActual + capacidadTanque < distanciaTotal)
		{
			// a.
			int estacion = estaciones.back();
			int estacionAux;
			if (estaciones.size() > 1)
			{
				estacionAux = estaciones[estaciones.size() - 2];
			}
			else
			{
				estacionAux = distanciaTotal;
			}
			// b.
			if (estacionAux > posActual + capacidadTanque)
			{
				if (estacion <= posActual + capacidadTanque)
				{
					estacionesParar.push_back(estacion);
					posActual = estacion;
				}
				else
				{
					return { -1 };
				}
			}
			// c.
			estaciones.pop_back();
		}
	}

	if (posActual + capacidadTanque >= distanciaTotal)
	{
		return estacionesParar;
	}
	else
	{
		return { -1 };
	}
	
}
/*

110
50
10 50
85 25

estacion = 85
estacion aux = 100 
posActual = 25

100 > 75


guardamos
*/

void mainEjercicio1()
{
	int distanciaTotal, capacidadTanque, numeroEstaciones;
	std::vector<int> estaciones, estacionesParadas;
	std::cout << "Ingrese la distancia a recorrer: ";
	std::cin >> distanciaTotal;
	std::cout << "Ingrese la capacidad del tanque: ";
	std::cin >> capacidadTanque;
	std::cout << "Ingrese el numero de estaciones: ";
	std::cin >> numeroEstaciones;

	estaciones = crearEstaciones(numeroEstaciones);

	estacionesParadas = recorrerAutopista(estaciones, distanciaTotal, capacidadTanque);

	if (estacionesParadas.size() == 0)
	{
		std::cout << "-";
	}
	else
	{
		std::cout << estacionesParadas.size() << std::endl;

		for (const auto estacion : estacionesParadas)
		{
			std::cout << estacion << " ";
		}
	}
}

/* EJERCICIO 2*/
/* Divide conquista
Inputs:
Línea 1: entero N número de jugadores.
Línea 2: N enteros distintos en el rango [1, N] 
— los números de ranking oficial de los jugadores en su nuevo orden de clasificación.

Outputs:
1 entero, numero de inversiones del arreglo

Permutaciones (NivelSorpresa)

ejemplo 3 1 4 2 5

3 > 1 -> 1 permutacion
3 < 4 -> 0 permutacion
3 > 2 -> 1 permutacion
3 < 5 -> 0 permutacion

-> Asi con cada indice hasta size() - 2

-> Total = 3 permutacion (3,1) , (3,2) , (4,2)

Original{ 3 , 2 , 4, 1 , 5}
	
	izq = { 3 , 2 }
	der = { 4 , 1 , 5}
	
		RECUR 1
		ORIGINAL { 3 , 2 }
		izq = { 3 }
		der = { 2 }
		
		i = 0
		j = 0
		k = 0

			
*/

int contarInversiones(std::vector<int>& arr) {
	if (arr.size() <= 1) return 0;

	int mid = arr.size() / 2;

	std::vector<int> izquierda(arr.begin(), arr.begin() + mid);
	std::vector<int> derecha(arr.begin() + mid, arr.end());

	int inv = 0;

	// Contar en cada mitad
	inv += contarInversiones(izquierda);
	inv += contarInversiones(derecha);

	// Merge + contar cruzadas
	int i = 0, j = 0, k = 0;

	while (i < izquierda.size() && j < derecha.size()) {
		if (izquierda[i] <= derecha[j]) {
			arr[k++] = izquierda[i++];
		}
		else {
			arr[k++] = derecha[j++];
			inv += izquierda.size() - i; // ?? clave
		}
	}

	// Copiar lo que queda
	while (i < izquierda.size()) arr[k++] = izquierda[i++];
	while (j < derecha.size()) arr[k++] = derecha[j++];

	return inv;
}

void mainEjercicio2()
{
	std::vector<int> arr = { 3, 1, 4, 2, 5 };

	int resultado = contarInversiones(arr);

	std::cout << "Cantidad de pares: " << resultado << std::endl;
}


/* EJERCICIO 3 */
/* FUERZA BRUTA
 
Logica:

Se debe encontrar la cantidad de combinaciones (ascendentes) que cumplan que la suma de numeros
del codigo posible sea la SumaObjetivo 

INPUTS

Linea 1 : cantidadNumerosDisponibles, cantidadNumerosCodigo, SumaObjetivo
OUTPUTS

Cantidad combinaciones
combinaciones

RESTRICCIONES

en los numeros disponibles no existe ningun numero repetido
en el codigo no existe ningun numero repetido

1 3 4 5 6

[FASLE,FALSE,FALSE,FALSE,FALSE]

1 + 3 + 4
1 + 3 + 5
1 + 3 + 6

1 + 4 + 5
1 + 4 + 6

1 + 5 + 6

1 + 6 correct -> se guarda

3 + 4 correct -> se guarda
3 + 5
3 + 6

4 + 5
4 + 6

5 + 6

*/

std::vector<int> generarNumerosDisponibles(int cantidadNumerosDisponibles)
{
	std::vector<int> numeros;
	std::cout << "Ingrese los numeros disponibles" << std::endl;
	for (int i = 0; i < cantidadNumerosDisponibles; i++)
	{
		std::cin >> numeros[i];
	}
	return numeros;
}
void codigosPosibles(
	std::vector<int>& numerosDisponibles, 
	std::vector<int>& actual,
	std::vector<bool>& numerosUsados,
	std::vector<std::vector<int>>& combinaciones,
	int SumaObjetivo,
	int SumaActual,
	int numerosCodigo,
	int ind
)
{
	if (SumaActual == SumaObjetivo && numerosCodigo == actual.size())
	{
		combinaciones.push_back(actual);
		return;
	}

	if (SumaActual > SumaObjetivo || actual.size() > numerosCodigo ) return;

	for (int i = ind; i < numerosDisponibles.size(); i++)
	{
		if (!numerosUsados[i])
		{
			numerosUsados[i] = true;
			actual.push_back(numerosDisponibles[i]);
			codigosPosibles(
				numerosDisponibles,
				actual,
				numerosUsados,
				combinaciones,
				SumaObjetivo, SumaActual + actual.back(),
				numerosCodigo,
				i + 1
			);
			numerosUsados[i] = false;
			actual.pop_back();
		}
	}
}

void mainEjercicio3()
{
	int CantnumerosDisponibles;
	int numerosCodigo = 2;
	int SumaObjetivo = 7;
	/*
	std::cout << "Ingrese la cantidad de numeros Disponibles: ";
	std::cin >> CantnumerosDisponibles;
	std::cout << "Ingrese la cantidad de numeros del codigo: ";
	std::cin >> numerosCodigo;
	std::cout << "Ingrese la suma objetivo: ";
	std::cin >> SumaObjetivo;
	*/
	//std::vector<int> numerosDisponibles = generarNumerosDisponibles(CantnumerosDisponibles);
	std::vector<int> numerosDisponibles = { 1, 3, 4, 5, 6 };
	std::vector<bool> numerosUsados(numerosDisponibles.size(), false);
	std::vector<std::vector<int>> combinaciones;
	std::vector<int> actual = {};
	codigosPosibles(numerosDisponibles, actual, numerosUsados, combinaciones, SumaObjetivo, 0, numerosCodigo, 0);

	std::cout << combinaciones.size() << std::endl;

	for (const auto combinacion : combinaciones)
	{
		for (const auto dato : combinacion)
		{
			std::cout << dato << " ";
		}
		std::cout << std::endl;
	}
}
int main() {

}


