#pragma once
#include "Nodo.h"
#include <iostream>
#include <fstream> 
#include <unordered_map>
#include "Arbol.h"

using namespace std;

template <class T>
class Grafo
{
private:
	unordered_map<T, Nodo<T>> graf;
public:
	unordered_map<T, Nodo<T>>& getGrafo();
	Grafo();
	void leerArchivo();
	void InsertarAristaConPeso(T dato1, T dato2, int peso);
	void MostrarGrafo();
	void Kruskal(unordered_map<T, Nodo<T>> graf);
	T BuscarCiclo(T nodo);
	

};

template<class T>
inline unordered_map<T, Nodo<T>>& Grafo<T>::getGrafo()
{
	return graf;
}

template<class T>
inline Grafo<T>::Grafo()
{
}

template<class T>
inline void Grafo<T>::leerArchivo()
{
	ifstream archivo("Valorado Bolivia Texto.txt");
	T dato1;
	T dato2;
	int peso;
	int contador = 0;

	if (!archivo.is_open())
	{
		cout << "No se pudo abrir el archivo." << endl;
	}
	while (archivo >> dato1 >> dato2 >> peso)
	{
		InsertarAristaConPeso(dato1, dato2, peso);
		contador++;
	}
	if (archivo.fail() && !archivo.eof())
	{
		cout << "Error de formato en el archivo." << endl;
	}
	else
	{
		cout << "Lectura de archivo completada. Se leyeron " << contador << " aristas." << endl;
	}
	archivo.close();
}


template<class T>
inline void Grafo<T>::InsertarAristaConPeso(T dato1, T dato2, int peso)
{
	graf[dato1].lista.push_back(make_pair(peso, dato2));
	graf[dato2].lista.push_back(make_pair(peso, dato1));
}


template<class T>
inline void Grafo<T>::MostrarGrafo()
{
	for (auto& nodo : graf)
	{
		cout << nodo.first << " -> ";
		for (auto& arista : nodo.second.lista)
		{
			cout << arista.second << " (Peso: " << arista.first << ") ";
		}
		cout << endl;
	}
}
/*
template<class T>
inline void Grafo<T>::Kruskal(unordered_map<T, Nodo<T>> graf)
{
	Arbol ColaP;
	for (auto& nodo : graf) {
		T nodoOrigen = nodo.first;
		for (auto& arista : nodo.second.lista) {
			int peso = arista.first;
			T nodoDestino = arista.second;
			ColaP.insertar(peso, nodoOrigen, nodoDestino);
		}
	}
	for (auto& nodo : graf) {
		nodo.second.padre = nodo.first;
	}
	int total = 0;
	int cont = 0;
	while (cont < graf.size() - 1 && !ColaP.estaVacio()) {
		NodoM menorArista = ColaP.Eliminar();
		int peso = menorArista.getElemento();
		T nodoOrigen = menorArista.getOrigen();
		T nodoDestino = menorArista.getDestino();
		T setOrigen = BuscarCiclo(nodoOrigen);
		T setDestino = BuscarCiclo(nodoDestino);
		if (setOrigen != setDestino) {
			InsertarAristaConPeso(nodoOrigen, nodoDestino, peso);
			total += peso;
			graf[setOrigen].padre = setDestino;
			cont++;
		}
	}
	cout << "Costo total del MST: " << total << endl;
}
template<class T>
inline T Grafo<T>::BuscarCiclo(T nodo)
{
	if (graf[nodo].padre != nodo)
	{
		graf[nodo].padre = BuscarCiclo(graf[nodo].padre);
	}
	return graf[nodo].padre;
}
*/
template<class T>
inline void Grafo<T>::Kruskal(unordered_map<T, Nodo<T>> graf) {
	Arbol ColaP;
	// Insertar todas las aristas en la cola de prioridad
	for (auto& nodo : graf) {
		T nodoOrigen = nodo.first;
		for (auto& arista : nodo.second.lista) {
			int peso = arista.first;
			T nodoDestino = arista.second;
			ColaP.insertar(peso, nodoOrigen, nodoDestino);
		}
	}

	// Inicializar cada nodo como su propio conjunto
	for (auto& nodo : graf) {
		nodo.second.padre = nodo.first;
	}

	int total = 0; // Variable para el costo total del MST
	int cont = 0; // Contador para las aristas en el MST
	int numVertices = graf.size(); // N�mero de v�rtices en el grafo

	cout << "vertices :"<<numVertices << endl;

	// Empezamos a construir el MST
	while (cont < numVertices ) {
		cout << "cont :"<< cont << "vertices: " << numVertices << endl;

		NodoM menorArista = ColaP.Eliminar();
		int peso = menorArista.getElemento();


		T nodoOrigen = menorArista.getOrigen();
		T nodoDestino = menorArista.getDestino();
		// Encontrar el conjunto de cada nodo
		T setOrigen = BuscarCiclo(nodoOrigen);
		T setDestino = BuscarCiclo(nodoDestino);

		// Si pertenecen a diferentes conjuntos, agregamos la arista al MST
		if (setOrigen != setDestino) {
			cout << "Agregando arista " << nodoOrigen << " - " << nodoDestino << " con peso " << peso << endl;
			InsertarAristaConPeso(nodoOrigen, nodoDestino, peso);
			total += peso;
			graf[setOrigen].padre = graf[setDestino].padre; // Union de conjuntos
			cont++;
		}
	}

	cout << "Costo total del MST: " << total << endl;
	if (cont != numVertices - 1) {
		cout << "Advertencia: El MST no pudo conectar todos los nodos." << endl;
	}
}

template<class T>
inline T Grafo<T>::BuscarCiclo(T nodo) {
	if (graf[nodo].padre != nodo) {
		// cout << "Nodo " << nodo << " no es su propio padre. Padre actual: " << graf[nodo].padre << endl;
		// graf[nodo].padre = BuscarCiclo(graf[nodo].padre); // Caminos comprimidos
		// cout << "Actualizado padre de " << nodo << " a " << graf[nodo].padre << endl;
		nodo = graf[nodo].padre;
	}
		cout <<  graf[nodo].padre <<endl;
	return nodo;
}

