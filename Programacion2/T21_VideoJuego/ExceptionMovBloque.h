#pragma once

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class ExceptionMovBloque :
    public exception
{
private:
    string mensaje;
public:
    ExceptionMovBloque();
    ~ExceptionMovBloque();

    const char* what() const;
};

