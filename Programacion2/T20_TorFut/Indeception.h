#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Indeception:public exception
{
private:
	string mensaje;
public:
	Indeception(string nom);
	~Indeception();
	const char* what() const;
};

