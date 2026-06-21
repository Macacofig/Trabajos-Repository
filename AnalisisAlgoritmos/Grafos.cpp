#include <iostream>
#include <vector>
#include <list>

using namespace std;
/*
// u = origen
// v = destino


// 1. Matriz de Adyacencia
class GraphMatrix {
private:
    vector<vector<int>> adjMatrix;
    int vertices;
    bool isDirected;
public:
    GraphMatrix(int v, bool directed = false) {
        vertices = v;
        isDirected = directed;
        adjMatrix.resize(v, vector<int>(v, 0));
    }
    void addEdge(int u, int v, int weight = 1) {
        adjMatrix[u][v] = weight;
        if (!isDirected) {
            adjMatrix[v][u] = weight;
        }
    }
    void removeEdge(int u, int v) {
        adjMatrix[u][v] = 0;
        if (!isDirected) {
            adjMatrix[v][u] = 0;
        }
    }
    bool hasEdge(int u, int v) {
        return adjMatrix[u][v] != 0;
    }
    void printGraph() {
        cout << "Matriz de Adyacencia:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    int getVertices() {
        return vertices;
    }
    vector<vector<int>>& getMatrix() {
        return adjMatrix;
    }
};

// 2. Lista de Adyacencia
class GraphList {
private:
    vector<list<pair<int, int>>> adjList; // {destino, peso}
    int vertices;
    bool isDirected;
public:
    GraphList(int v, bool directed = false) {
        vertices = v;
        isDirected = directed;
        adjList.resize(v);
    }
    void addEdge(int u, int v, int weight = 1) {
        adjList[u].push_back({ v, weight });
        if (!isDirected) {
            adjList[v].push_back({ u, weight });
        }
    }
    void removeEdge(int u, int v) {
        adjList[u].remove_if([v](pair<int, int> p) { return p.first == v; });
        if (!isDirected) {
            adjList[v].remove_if([u](pair<int, int> p) { return p.first == u; });
        }
    }
    bool hasEdge(int u, int v) {
        for (auto& p : adjList[u]) {
            if (p.first == v) return true;
        }
        return false;
    }
    void printGraph() {
        cout << "Lista de Adyacencia:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (auto& p : adjList[i]) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
    int getVertices() {
        return vertices;
    }
    vector<list<pair<int, int>>>& getList() {
        return adjList;
    }
};

// 3. Lista de Aristas
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};
class EdgeList {
private:
    vector<Edge> edges;
    int vertices;
    bool isDirected;
public:
    EdgeList(int v, bool directed = false) {
        vertices = v;
        isDirected = directed;
    }
    void addEdge(int u, int v, int weight = 1) {
        edges.push_back(Edge(u, v, weight));
        if (!isDirected) {
            edges.push_back(Edge(v, u, weight));
        }
    }
    void printGraph() {
        cout << "Lista de Aristas:\n";
        for (auto& e : edges) {
            cout << e.u << " -> " << e.v << " (peso: " << e.weight << ")\n";
        }
    }
    vector<Edge>& getEdges() {
        return edges;
    }
    int getVertices() {
        return vertices;
    }
};
*/
/*
#include <algorithm>

class GraphList 
{
private:
    vector<list<pair<int, int>>> adjList;
    int vertices;
    bool isDirected;

public:
    GraphList(int v, bool directed = false) 
    {
        vertices = v;
        isDirected = directed;
        adjList.resize(v + 1);
    }

    void addEdge(int u, int v, int weight = 1) 
    {
        adjList[u].push_back({ v, weight });

        if (!isDirected) {
            adjList[v].push_back({ u, weight });
        }
    }

    vector<list<pair<int, int>>>& getList() 
    {
        return adjList;
    }

    int getVertices() 
    {
        return vertices;
    }
};

vector<int> parent;
vector<bool> visited;

int cycle_start = -1;
int cycle_end = -1;

bool dfs(int node, int pardre, GraphList& g)
{
    visited[node] = true;

    for (auto& It_vecinos : g.getList()[node])
    {
        int vecino = It_vecinos.first;

        if (vecino == pardre) continue;

        if (visited[vecino]) {
            cycle_end = node;
            cycle_start = vecino;
            return true;
        }

        parent[vecino] = node;

        if (dfs(vecino, node, g))
            return true;
    }

    return false;
}

int main() 
{

    int n, m;
    cin >> n >> m;

    GraphList g(n);

    for (int i = 0; i < m; i++) 
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    // n + 1 -> Empezar desde el nodo 1
    visited.assign(n + 1, false);// vertices visitados   
    parent.assign(n + 1, -1);//padres de vertices 

    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i]) 
        {
            if (dfs(i, -1, g))
                break;
        }
    }

    vector<int> cycle;//Vector para guardar el ciclo obtenido

    cycle.push_back(cycle_start);

    for (int vertice = cycle_end; vertice != cycle_start; vertice = parent[vertice]) 
    {
        cycle.push_back(vertice);
    }

    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";

    for (int vertice : cycle) 
    {
        cout << vertice << " ";
    }

    return 0;
}


vector<int> state;
vector<int> parent;

int cycle_start = -1;
int cycle_end = -1;

bool dfs(int node, GraphList& g) {

    state[node] = 1;

    for (auto& edge : g.getList()[node]) {

        int neigh = edge.first;

        // ciclo
        if (state[neigh] == 1) {
            cycle_start = neigh;
            cycle_end = node;
            return true;
        }

        // seguir DFS
        if (state[neigh] == 0) {

            parent[neigh] = node;

            if (dfs(neigh, g))
                return true;
        }
    }

    state[node] = 2;

    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // TRUE = dirigido
    GraphList g(n, true);

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        g.addEdge(a, b);
    }

    state.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {

        if (state[i] == 0) {

            if (dfs(i, g))
                break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;

    cycle.push_back(cycle_start);

    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }

    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";

    for (int x : cycle)
        cout << x << " ";

    cout << "\n";
}
*/

/*
KOSARAJU(G)
    Stack S = vacía
    visited = array[V] inicializado en false
    // Primera DFS: llenar pila con orden de finalización
    for cada vértice v en G
        if not visited[v]
            FILL_ORDER(v, visited, S)
    // Crear grafo transpuesto
    G_transpose = TRANSPOSE(G)
    // Resetear visited
    visited = array[V] inicializado en false
    // Segunda DFS en el grafo transpuesto
    while S no está vacía
        v = S.pop()
        if not visited[v]
            SCC = []
            DFS_COLLECT(G_transpose, v, visited, SCC)
            imprimir SCC

FILL_ORDER(v, visited, S)
    visited[v] = true
    for cada vecino u de v
        if not visited[u]
            FILL_ORDER(u, visited, S)
    S.push(v)  // Agregar después de visitar todos los vecinos

DFS_COLLECT(G, v, visited, SCC)
    visited[v] = true
    SCC.add(v)
    for cada vecino u de v
        if not visited[u]
            DFS_COLLECT(G, u, visited, SCC)

TRANSPOSE(G)
    G_t = nuevo grafo con V vértices
    for cada arista (u, v) en G
        G_t.agregar_arista(v, u)  // Invertir la arista
    return G_t
*/

/*
1 -> 0
0 -> 2
2 -> 1
0 -> 3
3 -> 4
*/

/*
Llevar a codigo el algoritmo de KOSARAJU
SCC 1: 0 ,1, 2 # que todos los vertices se alcanza(que tienen caminos)
SCC 2: 3 # que es un vertice sin caminos de retorno
SCC 3: 4 # que es un vertice aislado (que no tiene salida)


int main() {
    KosarajuSCC g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.printSCCs();
    return 0;
}*/

// CLASE GRAFO
#include <iostream>
#include <vector>
#include <list>

using namespace std;
class GraphList 
{
private:
    int vertices;
    vector<list<int>> adjList;

public:
    GraphList(int v) 
    {
        vertices = v;
        adjList.resize(v);
    }

    // Agregar arista
    void addEdge(int u, int v) 
    {
        adjList[u].push_back(v);
    }

    // Obtener lista de adyacencia
    vector<list<int>>& getAdjList() 
    {
        return adjList;
    }

    // Obtener cantidad de vértices
    int getVertices() 
    {
        return vertices;
    }
};

// ALGORITMO KOSARAJU
#include <stack>
class KosarajuSCC 
{
private:

    // DFS para llenar pila
    void fillOrder(
        int v, // nodo actual
        vector<bool>& visited,//nodos visitados
        stack<int>& S, // aqui se guardan los nodos en orden de finalizacion
        vector<list<int>>& adj //lista de adyacencias del grafo
    ) {
        visited[v] = true;

        for (int u : adj[v]) 
        {
            if (!visited[u]) 
            {
                fillOrder(u, visited, S, adj);
            }
        }

        S.push(v);
    }

    // DFS para recolectar SCC
    void DFSCollect(
        int v, // nodo actual
        vector<bool>& visited, //nodos visitados
        vector<int>& SCC, // aqui se guardan los nodos del componente
        vector<list<int>>& adj //lista de adyacencias del grafo
    ) {
        visited[v] = true;
        SCC.push_back(v);

        for (int u : adj[v]) 
        {
            if (!visited[u]) 
            {
                DFSCollect(u, visited, SCC, adj);
            }
        }
    } // -> SCC contiene los nodos conectados fuertemente

    // Transponer grafo -> Inventir grafo (0 -> 1 a 0 <- 1)
    GraphList getTranspose(GraphList& g) 
    {

        int V = g.getVertices();

        GraphList gT(V);

        vector<list<int>>& adj = g.getAdjList();

        for (int u = 0; u < V; u++) // recorrer todas las aristas
        {

            for (int v : adj[u]) // recorrer vecinos
            {
                gT.addEdge(v, u);
            }
        }

        return gT;
    }

public:

    void printSCCs(GraphList& g) 
    {

        int V = g.getVertices();

        vector<list<int>>& adj = g.getAdjList();

        stack<int> S;

        vector<bool> visited(V, false);

        // 1. Primera DFS
        for (int i = 0; i < V; i++) 
        {

            if (!visited[i]) 
            {
                fillOrder(i, visited, S, adj);
            }
        }

        // 2. Grafo transpuesto
        GraphList gT = getTranspose(g);

        vector<list<int>>& transposeAdj = gT.getAdjList();

        // 3. Reset visited
        fill(visited.begin(), visited.end(), false); // llenar los visitados de falsos

        int contador = 1;

        // 4. Segunda DFS
        while (!S.empty()) // usar el stack
        {

            int v = S.top(); // utilizar ultimo elemento
            S.pop(); //eliminarlo

            if (!visited[v]) 
            {

                vector<int> SCC;

                DFSCollect(v, visited, SCC, transposeAdj);

                cout << "SCC " << contador++ << ": ";

                for (int nodo : SCC) 
                {
                    cout << nodo << " ";
                }

                cout << endl;
            }
        }
    }
};

// =======================
// MAIN
// =======================
int main() {

    GraphList g(5);

    g.addEdge(1, 3);
    g.addEdge(3, 0);
    g.addEdge(2, 1);
    g.addEdge(4, 3);
    g.addEdge(3, 2);
    g.addEdge(0, 4);

    KosarajuSCC kosaraju;

    kosaraju.printSCCs(g);

    return 0;
}