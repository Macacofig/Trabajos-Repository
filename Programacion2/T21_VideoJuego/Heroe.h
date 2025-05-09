#pragma once
#include "Personaje.h"
class Heroe :
    public Personaje
{
public:
    Heroe(int id, int x, int y);
    ~Heroe();

    string toString();
};

