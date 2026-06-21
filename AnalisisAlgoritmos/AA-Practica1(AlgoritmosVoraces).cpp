
#include <iostream>
#include <vector>
#include <algorithm>

/*
* MATEO GAEL FIGUEROA CHAVEZ 
* NATALY RAMIREZ MACHICADO
* OSTIN LISANDRO COLQUE
 

# Estructura de intervalo : (inicio, fin)

def ordenar_intervalos(intervalos) :
    return sorted(intervalos, key = lambda x : x[1])  # por fin


    def seleccionar_puntos(intervalos) :

    # 1. INICIALIZAR
    puntos = []
    ultimo_punto = float(-inf) # valor inicial para asegurar primera entrada

    # 2. ORDENAR candidatos
    intervalos = ordenar_intervalos(intervalos)

    # 3. MIENTRAS haya candidatos(recorrer lista)
    for inicio, fin in intervalos :

# a.SELECCIONAR el mejor candidato(fin del intervalo)

# b.VERIFICAR factibilidad
if inicio > ultimo_punto:
puntos.append(fin)     # agregar a solución
ultimo_punto = fin     # actualizar referencia

# c.ELIMINAR candidato → implícito al avanzar en el for

# 4. RETORNAR solución
return puntos
*/


// Ordenar por el inicio del intervalo (extremo izquierdo)
// De mayor a menor (para luego procesar con .back())
bool comparar(std::pair<int,int> a, std::pair<int, int> b) {
    return a.first > b.first;
}

// Funcion de ordenar  intervalos
std::vector<std::pair<int,int>> ordenar_intervalos(std::vector<std::pair<int,int>> intervalos) 
{
    // Candidatos: todos los intervalos posibles
    // Estrategia: ordenarlos por extremo izquierdo
    std::sort(intervalos.begin(), intervalos.end(), comparar);
    return intervalos;
}

// Entrada: n intervalos dados por el usuario
std::vector<std::pair<int, int>> crear_intervalos(int n)
{
    std::vector<std::pair<int, int>> intervalos; // conjunto de intervalos 
    std::pair<int, int> aux;
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "intervalo " << i << " : " << std::endl;
        std::cin >> a;
        std::cin >> b;
        aux.first = a;
        aux.second = b;
        intervalos.push_back(aux);
    }
    return intervalos;
}

// Función objetivo: minimizar la cantidad de puntos (transmisores)
// que cubren todos los intervalos
std::vector<int> crear_puntos(std::vector<std::pair<int, int>> intervalos)
{
    //Inicializar
    std::vector<int> puntos = {}; // solución final (transmisores)

    // Inicialización: valor muy pequeño (ningún punto colocado aún)
    int ultimo_punto = -1000;

    std::pair<int, int> intervaloPair;
    
    // Ordenar intervalos
    intervalos = ordenar_intervalos(intervalos);

    // Mientras haya intervalos por procesar
    while(!intervalos.empty())
    {
        // a) Seleccionar candidato (intervalo actual)
        intervaloPair = intervalos.back(); 

        // b) Verificar si el intervalo ya está cubierto
        // Restricción: un punto cubre si está dentro del intervalo
        if (ultimo_punto < intervaloPair.first)
        {
            // Elección greedy:
            // elegir el extremo derecho maximiza cobertura
            puntos.push_back(intervaloPair.second);

            // actualizar último punto elegido
            ultimo_punto = intervaloPair.second;
        }

        // c) Eliminar intervalo ya procesado
        intervalos.pop_back(); 
    }
    return puntos;
}

int main()
{
    std::vector<std::pair<int, int>> intervalos;
    std::vector<int> puntos;

    // Entrada: cantidad de intervalos
    intervalos = crear_intervalos(4);

    // Resolver problema (selección greedy)
    puntos = crear_puntos(intervalos);

    // Salida: cantidad mínima de transmisores
    std::cout << puntos.size() << std::endl;

    // Mostrar puntos seleccionados
    for (auto& punto : puntos)
    {
        std::cout << punto << " ";
    }
}