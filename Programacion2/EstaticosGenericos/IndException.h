#pragma once
#include "iostream"
#include "string"
#include "sstream"
using namespace std;
class IndException :public exception
{
private:
	string mensaje;
public:
	IndException(int ind);
    ~IndException();
	const char* what() const;
};

