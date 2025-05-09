#pragma once
#include "Personaje.h"
class Villano :
    public Personaje
{
public:
    Villano(int id, int x, int y);
    ~Villano();

    string toString();
};

