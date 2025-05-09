#pragma once
#include "Objeto.h"
class Bloque :
    public Objeto
{
public:
    Bloque(int id, int x, int y);
    ~Bloque();

    string toString();
};

