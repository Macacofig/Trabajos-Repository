#include "ListaGen.h"
#include "ArrayGen.h"
#include "Equipo.h"
#include "Evento.h"
#include "SingletonEquipos.h"
#include "Federacion.h"

void ejemplo1()
{
    ArrayGen<Equipo> equipos;
}
void ejemplo2()
{
    ArrayGen<Equipo> equipos;
    equipos.registrar(new Equipo("stronger", "e1"));
    equipos.registrar(new Equipo("Barsa", "e2"));
}
void ejemplo3()
{
    ArrayGen<Equipo> equipos;
    equipos.registrar(new Equipo("stronger", "e1"));
    equipos.registrar(new Equipo("Barsa", "e2"));
    equipos.registrar(new Equipo("real", "e3"));
    cout << equipos.toJson(Equipo::toJson);
}
void ejemplo4()
{
    ArrayGen<Evento> eventos;
    eventos.registrar(new Evento(1, "e1"));
    eventos.registrar(new Evento(2, "e2"));
    eventos.registrar(new Evento(3, "e3"));
    cout << eventos.toJson(Evento::toJson);
}
void ejemplo5()
{
    ArrayGen<Equipo> equipos;
    equipos.registrar(new Equipo("stronger", "e1"));
    equipos.registrar(new Equipo("Barsa", "e2"));
    equipos.registrar(new Equipo("real", "e3"));
    equipos.ordenar(Equipo::cmpNombreASC);
    cout << equipos.toJson(Equipo::toJson);
    equipos.ordenar(Equipo::cmpNombreDSC);
    cout << equipos.toJson(Equipo::toJson);
}
void ejemplo6()
{
    ArrayGen<Equipo> equipos;
    equipos.registrar(new Equipo("x", "x"));
    equipos.registrar(new Equipo("y", "y"));
    equipos.registrar(new Equipo("z", "z"));
    Equipo equipoBuscar("x");
    Equipo* equipoencontrado = equipos.buscar(&equipoBuscar);
    if (equipoencontrado != NULL)
    {
        cout << equipoencontrado->toJson() << endl;
    }
}
void ejemplo7()
{
    ListaGen<Equipo> equipos;
    equipos.registrar(new Equipo("stronger", "e1"));
    equipos.registrar(new Equipo("Barsa", "e2"));
    equipos.registrar(new Equipo("real", "e3"));
    cout << equipos.toJson(Equipo::toJson);
}
void ejemplo8()
{
    int a, b;
    while (true)
    {
        try {
            cout << "Ingrese a: ";
            cin >> a;
            cout << "Inrese b: ";
            cin >> b;
            if (b == 0) throw string("No div por 0");
            int sum = a + b;
            int div = a / b;
            int rest = a - b;
            int mult = a * b;
            cout << "sum: " << sum << endl;
            cout << "div: " << div << endl;
            cout << "rest: " << rest << endl;
            cout << "mult: " << mult << endl;
        }
        catch (string& err) {
            cout << "Datos invalidos: " << err << endl;
        }
    }
}
void ejemplo9()
{
    ArrayGen<Equipo> equipos;
    equipos.registrar(new Equipo("stronger", "e1"));
    equipos.registrar(new Equipo("Barsa", "e2"));
    equipos.registrar(new Equipo("real", "e3"));
    cout << equipos[10]->toJson();

}
void ejemplo10()
{

    try {
        ejemplo9();
    }
    catch (string& err)
    {
        cout << err << endl;
    }
    catch (exception& err)
    {
        cout << err.what() << endl;
    }
}
void ejemplo11()
{

    try {
        try {
            ejemplo9();
        }
        catch (string& err)
        {
            cout << err << endl;
        }
    }
    catch (exception& err)
    {
        cout << err.what() << endl;
    }
}
void ejemplo12()
{
    try
    {
        ArrayGen<Equipo> equipos;
        equipos.registrar(new Equipo("stronger", "e1"));
        equipos.registrar(new Equipo("Barsa", "e2"));
        equipos.registrar(new Equipo("real", "e3"));
        cout << equipos[-1]->toJson();
    }
    catch (exception& err)
    {
        cout << err.what() << endl;
    }

}

void ejemplo13()
{
    ArrayGen<Equipo> equipos;
    equipos.registrar(new Equipo("stronger", "e1"));
    equipos.registrar(new Equipo("Barsa", "e2"));
    equipos.registrar(new Equipo("real", "e3"));
    cout << equipos.toJson(Equipo::toJson);
    ArrayGen<Evento> eventos;
    eventos.registrar(new Evento(1, "e1"));
    eventos.registrar(new Evento(2, "e2"));
    eventos.registrar(new Evento(3, "e3"));
    cout << eventos.toJson(Evento::toJson);
}

void ejemplo14()
{
    SingletonEquipos::getInst().getEquipos().registrar(new Equipo("x", "x"));
    SingletonEquipos::getInst().getEquipos().registrar(new Equipo("y", "y"));
    SingletonEquipos::getInst().getEquipos().registrar(new Equipo("z", "z"));
    SingletonEquipos::getInst().getEquipos().registrar(new Equipo("w", "w"));
    cout<<SingletonEquipos::getInst().getEquipos().toJson(Equipo::toJson)<<endl;
}

void ejemplo15()
{
    SingletonEquipos::getInst().getEquipos().registrar(new Equipo("a", "a"));

    Federacion ucb("ucb");
    ucb.registrarEqiopo("x", "x");
    ucb.registrarEqiopo("y", "y");
    ucb.registrarEqiopo("z", "z");
    ucb.mostrar();
}
int main()
{
    ejemplo15();
}
