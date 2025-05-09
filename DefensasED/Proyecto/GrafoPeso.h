#pragma once
#include "Nodo.h"

template <class T>
class GrafoPeso
{
private:
	unordered_map<T, Nodo<T>> G;
public:
	GrafoPeso();
	~GrafoPeso();
	void Insertar(T origen, T destino);
	void LeerArchivo();
	void mostrar(unordered_map<T, Nodo<T>> Gg);
	unordered_map<T, Nodo<T>> getgrafo();
	//void InsertarC(unordered_map<T, Nodo<T>>& Gg,T origen, T destino);
	//void eliminarAristaC(unordered_map<T, Nodo<T>>& Gg,T origen, T destino);
	void CorteMin(unordered_map<T, Nodo<T>>& Gg);
	void contraer(unordered_map<T, Nodo<T>>& Gg, T v1, T v2);
	void AdiosAutoCiclo(unordered_map<T, Nodo<T>>& Gg, const T& v1);
	int contarAristas(unordered_map<T, Nodo<T>> Gg);
};

template <class T>
GrafoPeso<T>::GrafoPeso()
{
}

template <class T>
GrafoPeso<T>::~GrafoPeso()
{
}

template <class T>
void GrafoPeso<T>::Insertar(T origen, T destino)
{
	G[origen].v().push_back(destino);
	G[destino].v().push_back(origen);
}

/*
template <class T>
void GrafoPeso<T>::eliminarAristaC(unordered_map<T, Nodo<T>>& Gg,T origen, T destino)
{
	Gg[origen].eliminararista(destino);
	Gg[destino].eliminararista(origen);
}

template<class T>
void GrafoPeso<T>::InsertarC(unordered_map<T, Nodo<T>>& Gg, T origen, T destino)
{
	Gg[origen].v().push_back(destino);
	Gg[destino].v().push_back(origen);
}
*/

template <class T>
void GrafoPeso<T>::LeerArchivo()
{
	ifstream archivo("num.txt");
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo." << endl;
	}
	else
	{
		T origen; // Nodo origen
		while (archivo >> origen) {
			T destino; // Nodo destino

			while (archivo >> destino && destino != "-1") {
				// Insertar cada arista
				Insertar(origen, destino);
			}
		}
		archivo.close(); 
	}
	
}

template <typename T>
int GrafoPeso<T>::contarAristas(unordered_map<T, Nodo<T>> Gg) {
	int totalAristas = 0;

	for (auto& par : Gg) 
	{
		const auto& nodo = par.second; 
		totalAristas += nodo.v1().size();
	}

	return totalAristas / 2;
}

template <class T>
void GrafoPeso<T>::mostrar(unordered_map<T, Nodo<T>> Gg)
{
	cout << "Grafo resultante:" << endl;
	for (const auto& par : Gg) {
		const T& nodo = par.first;
		const Nodo<T>& data = par.second;

		cout << "Nodo: " << nodo << " - Conectado con: ";
		for (const auto& vecino : data.v1()) {
			cout << vecino << " ";
		}
		cout << endl;
	}
}

template <class T>
unordered_map<T, Nodo<T>> GrafoPeso<T>::getgrafo()
{
	return G;
}



template<class T>
void GrafoPeso<T>::CorteMin(unordered_map<T, Nodo<T>>& Gg)
{

	while (Gg.size() > 2)
	{
		auto it = Gg.begin();
		advance(it, rand() % Gg.size());//mover el iterador una cantidad de espacios (it, distancia)
		T v1 = it->first;

		vector<T>& adyacentes = Gg[v1].v();
		T v2 = adyacentes[rand() % adyacentes.size()];

		contraer(Gg, v1, v2);
		AdiosAutoCiclo(Gg, v1);
		//mostrar(Gg);
	}
}

template<class T>
void GrafoPeso<T>::contraer(unordered_map<T, Nodo<T>>& Gg, T v1, T v2)
{
	/*
	vector<T>* vec = &(Gg[v2].v());

	while (!vec->empty())
	{
		if (v1 != vec->operator[](0))
		{
			InsertarC(Gg,vec->operator[](0), v1);
		}
		eliminarAristaC(Gg,v2, vec->operator[](0));
	}
	*/
	vector<T>& adyacentes_v1 = Gg[v1].v(); 
	vector<T>& adyacentes_v2 = Gg[v2].v(); 

	adyacentes_v1.insert(adyacentes_v1.end(), adyacentes_v2.begin(), adyacentes_v2.end()); 

	for (auto& par : Gg) 
	{ 
		vector<T>& vec = par.second.v(); 
		replace(vec.begin(), vec.end(), v2, v1); 
	}
	Gg.erase(v2);
}

template <typename T>
void GrafoPeso<T>:: AdiosAutoCiclo(unordered_map<T, Nodo<T>>& Gg, const T& v1) 
{
	auto& nuevo_adyacentes = Gg[v1].v();
	nuevo_adyacentes.erase(remove(nuevo_adyacentes.begin(), nuevo_adyacentes.end(), v1),nuevo_adyacentes.end());
}
