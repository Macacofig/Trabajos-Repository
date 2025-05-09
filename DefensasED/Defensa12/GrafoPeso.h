#pragma once
#include "Nodo.h"
class GrafoPeso
{
private:
	unordered_map<string, Nodo> grafo;
public:
	GrafoPeso();
	~GrafoPeso();
	void Insertar(string origen, string destino, int tam);
	void LeerArchivo(string nombre);
	
	string buscarCiclo(string x);
	void kruskal();
	void mostrarAE(const vector<pair<string, string>>& arbolExpansion, int totalCosto, int aristasEnAE);
	void mostrar();
	void mostrarGrafo(unordered_map<string, vector<pair<int, string>>>& grafoAEM);

};

GrafoPeso::GrafoPeso()
{
}

GrafoPeso::~GrafoPeso()
{
}

void GrafoPeso::Insertar(string origen, string destino, int tam)
{
	grafo[origen].v().emplace_back(tam, destino);
	grafo[destino].v().emplace_back(tam, origen);
	if (grafo[origen].Padre().empty())
	{
		grafo[origen].sPadre(origen);
	}
	if (grafo[destino].Padre().empty())
	{
		grafo[destino].sPadre(destino);
	}
}

void GrafoPeso::LeerArchivo(string nombre)
{
	ifstream archivo(nombre);
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo." << endl;
	}
	else
	{
		string origen, destino; 
		int peso; 
		while (archivo >> origen >> destino >> peso) 
		{
			Insertar(origen, destino, peso); 
		}
		archivo.close(); 
	}
	
}

string GrafoPeso::buscarCiclo(string x)
{
	while (x != grafo[x].Padre())
	{
		x = grafo[x].Padre();
	}
	return x;
}

void GrafoPeso::kruskal() 
{
	vector<pair<string, string>> arbolExpansion; // Almacenará las aristas del MST
	int totalCosto = 0;
	int aristasEnAE = 0; // Contador de aristas en el árbol de expansión mínima

	// Cola de prioridad (min-heap) para ordenar aristas por peso
	priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<>> colaPrioridad;

	// Llenamos la cola de prioridad con todas las aristas del grafo
	for (const auto& [origen, nodo] : grafo) {
		for (const auto& [peso, destino] : nodo.v()) {
			colaPrioridad.emplace(peso, origen, destino); // Insertamos cada arista (peso, origen, destino)
		}
	}

	int cont = 0;
	int numAristas = colaPrioridad.size();

	// Bucle principal de Kruskal
	while (cont < numAristas && !colaPrioridad.empty()) {
		auto [peso, origen, destino] = colaPrioridad.top();
		colaPrioridad.pop();

		// Buscamos las raíces de los nodos de origen y destino
		string raizOrigen = buscarCiclo(origen);
		string raizDestino = buscarCiclo(destino);

		// Si las raíces son diferentes, no forman un ciclo
		if (raizOrigen != raizDestino) {
			arbolExpansion.emplace_back(origen, destino); // Añadimos la arista al MST
			totalCosto += peso; // Sumamos el peso al costo total
			grafo[raizOrigen].sPadre(raizDestino); // Unimos las componentes
			aristasEnAE++; // Incrementamos el contador de aristas en el MST
			cont++;
		}
	}

	// Mostramos el árbol de expansión mínima y el número de aristas
	mostrarAE(arbolExpansion, totalCosto, aristasEnAE);
}

void GrafoPeso::mostrarGrafo(unordered_map<string, vector<pair<int, string>>>& grafoAEM) 
{
	for (auto& it : grafoAEM) {
		string origen = it.first;
		cout << "Nodo: " << origen << " - Aristas: ";
		for (auto& arista : it.second) {
			cout << "(" << arista.first << ", " << arista.second << ") ";
		}
		cout << endl;
	}
}

void GrafoPeso::mostrarAE(const vector<pair<string, string>>& arbolExpansion, int totalCosto, int aristasEnAE) {
	cout << "Arbol de Expansión Mínima usando Kruskal:" << endl;
	for (const auto& arista : arbolExpansion) {
		cout << arista.first << " - " << arista.second << endl; // Usamos first y second en lugar de [origen, destino]
	}
	cout << "Costo total del MST: " << totalCosto << endl;
	cout << "Cantidad de aristas en el MST: " << aristasEnAE << endl;
}

