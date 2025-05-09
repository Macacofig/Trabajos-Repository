#pragma once

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class ExceptionCasOcupada :
    public exception
{
private:
    string mensaje;
public:
    ExceptionCasOcupada();
    ~ExceptionCasOcupada();

    const char* what() const;
};

