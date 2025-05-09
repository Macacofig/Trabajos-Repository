#pragma once
#include "Nodo.h"
template <class T>
class Grafo
{
private:
	vector<Nodo<T>> vec;
public:
	Grafo();
	~Grafo();
	void LeerArchivo(string nombre); 
	void InsertarArista(int x, int y); 
	void MostrarGrafo(); 
	void IniciarPadreMarca(); 
	bool Amplitud(int origen, int destino);
	bool Profundidad(int origen, int dest);
	void MostrarCamino(int origen, int destino);
};

template<class T>
Grafo<T>::Grafo()
{
}

template<class T>
Grafo<T>::~Grafo()
{
}

template<class T>
void Grafo<T>::LeerArchivo(string nombre)
{
	ifstream arc(nombre);
	string lineal;
	int a, b;
	while (getline(arc, lineal))
	{
		istringstream ss(lineal);
		ss >> a >> b;
		InsertarArista(a, b);
	}
	arc.close();
}

template<class T>
void Grafo<T>::InsertarArista(int x,int y)
{
	if (x >= vec.size() || y >= vec.size()) 
	{
		vec.resize(max(x, y) + 1, Nodo<T>(-1, false));  // Añadir nodos adicionales si faltan
	}
	vec[x].VecAristas().push_back(y);
	vec[y].VecAristas().push_back(x);
}

template<class T>
void Grafo<T>::MostrarGrafo()
{
	for (int i = 0; i < vec.size(); i++) {
		cout << "Nodo " << i << " tiene aristas hacia: ";
		for (int j = 0; j < vec[i].VecAristas().size(); j++) {
			cout << vec[i].VecAristas()[j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void Grafo<T>::IniciarPadreMarca()
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].sMarca(false);
		vec[i].sPadre(-1);
	}
}

template<class T>
bool Grafo<T>::Amplitud(int origen, int destino)
{
	bool encontre = false;
	if (origen >= vec.size() || destino >= vec.size())
	{
		cout << "El nodo de origen o destino está fuera del rango del grafo." << endl;
	}
	else
	{
		queue<int> cola; //cola
		vec[origen].sMarca(true);
		cola.push(origen); // ingresar 
		while (!cola.empty() && !encontre)
		{
			int i = 0;
			int vertice = cola.front(); // obtener primero sin eliminar
			cola.pop(); // eliminar primero
			vector<T>& adyacentes = vec[vertice].VecAristas();
			while (i < adyacentes.size() && !encontre)
			{
				int adya = adyacentes[i];
				if (!vec[adya].Marca())
				{
					vec[adya].sPadre(vertice);
					if (adya == destino)
					{
						encontre = true;
					}
					else
					{
						vec[adya].sMarca(true);
						cola.push(adya);
					}
				}
				i++;
			}
		}
	}
	return encontre;
}

template<class T>
bool Grafo<T>::Profundidad(int ori, int dest)
{
	bool encontrecam = false;
	if (ori >= vec.size() || dest >= vec.size()) 
	{
		cout << "El nodo de origen o destino está fuera del rango del grafo." << endl;
	}
	else
	{
		vec[ori].sMarca(true);
		int i = 0;
		while (i < vec[ori].VecAristas().size())
		{
			int adya = vec[ori].VecAristas()[i];
			if (!encontrecam && !vec[adya].Marca())
			{
				vec[adya].sPadre(ori);
				if (adya == dest)
				{
					encontrecam = true;
				}
				else
				{
					encontrecam = Profundidad(adya, dest);
				}
			}
			i++;
		}
	}
	return encontrecam;
}

template<class T>
void Grafo<T>::MostrarCamino(int origen, int destino)
{

	if (origen >= vec.size() || destino >= vec.size())
	{
		cout << "El nodo de origen o destino está fuera del rango del grafo." << endl;
	}
	else
	{
		vector<int> camino;
		int actual = destino;
		while (actual != origen)
		{
			camino.push_back(actual);
			actual = vec[actual].Padre();
		}
		camino.push_back(origen);

		for (int i = camino.size() - 1 ; i >= 0 ; i--)
		{
			cout << camino[i];
			if (i > 0)
			{
				cout << " -> ";
			}
		}
		cout << endl;
	}
}
