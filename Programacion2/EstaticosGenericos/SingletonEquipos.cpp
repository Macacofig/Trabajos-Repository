#include "SingletonEquipos.h"

SingletonEquipos::SingletonEquipos()
{
}
SingletonEquipos& SingletonEquipos::getInst()
{
    static SingletonEquipos instancia;
    return instancia;
}

SingletonEquipos::~SingletonEquipos()
{
}

ListaGen<Equipo>& SingletonEquipos::getEquipos()
{
    return equipos;
}
