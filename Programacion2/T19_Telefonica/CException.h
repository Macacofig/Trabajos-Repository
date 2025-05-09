#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class CException:public exception
{
private:
	string mensj;
public:
	CException(string nombre,string tipo,int pos);
	~CException();
	const char* what() const;
};

