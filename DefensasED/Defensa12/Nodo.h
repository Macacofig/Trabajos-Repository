#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class Nodo
{
private:
	bool marca;
	string padre;
	vector<pair<int,string>> vec;
public:
	Nodo();
	~Nodo();
	bool Marca();
	string Padre();
	vector<pair<int, string>>& v();
	void sPadre(string padre);
	void sMarca( bool marca);
};


Nodo::Nodo()
{
	padre = " ";
	marca = false;
}

Nodo::~Nodo()
{

}


bool Nodo::Marca()
{
	return marca;
}

 
string Nodo ::Padre()
{
	return padre;
}

vector<pair<int, string>>& Nodo::v()
{
	return vec;
}

 
void Nodo ::sPadre(string padre)
{
	this->padre=padre;
}

 
void Nodo ::sMarca(bool marca)
{
	this->marca = marca;
}

