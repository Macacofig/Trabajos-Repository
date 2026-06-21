#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

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
    vector<list<pair<int, int>>>& getList() {
        return adjList;
    }
};

// =========================
// DIJKSTRA
// =========================
vector<long long> dijkstra(GraphList& G, int source, int n) {

    // INF enorme
    const long long INF = 1e18;

    // distancias
    vector<long long> dist(n + 1, INF);//distancia a recorrer

    // cola de prioridad:
    // {distancia, nodo}
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[source] = 0;

    pq.push({ 0, source });

    auto& adj = G.getList();

    while (!pq.empty()) {

        int u = pq.top().second;
        long long currentDist = pq.top().first;

        pq.pop();

        // ignorar caminos viejos
        if (currentDist > dist[u]) {
            continue;
        }

        // recorrer vecinos
        for (auto& neighbor : adj[u]) {

            int v = neighbor.first;
            int weight = neighbor.second;

            long long alt = dist[u] + weight;

            if (alt < dist[v]) {

                dist[v] = alt;

                pq.push({ alt, v });
            }
        }
    }

    return dist;
}


int main()
{
    int n, m;
    int a, b, c;
    cin >> n >> m;
    GraphList G(n+1,true);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >>c;
        G.addEdge(a, b, c);
    }

    vector<long long> dist = dijkstra(G, 1, n);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

}

