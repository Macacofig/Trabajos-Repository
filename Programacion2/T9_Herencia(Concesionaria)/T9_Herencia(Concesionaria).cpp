
#include "Moto.h"
#include "Camioneta.h"
#include "ModVehiculos.h"
void ejemplo1()
{
    Moto moto("123", "Honda", 2020, 0, "Carretera");
    moto.mostrar();
}
void ejemplo2()
{
    Moto moto("123", "Honda", 2020, 0, "Carretera");
    Vehiculo v = moto;
    v.mostrar();
}
void ejemplo3()
{
    Moto moto("123", "Honda", 2020, 0, "Carretera");
    Vehiculo* v = &moto;
    v->mostrar();
}
void ejemplo4()
{
    Vehiculo* v = new Camioneta("456","toyota",2020,0,2000);
    v->mostrar();
}
void ejemplo5()
{
    Vehiculo* v[3];
    v[0] = new Camioneta("456", "toyota", 2020, 0, 2000);
    v[1] = new Moto("456", "toyota", 2020, 0, "carretera");
    v[2] = new Camioneta("456", "toyota", 2020, 0, 2000);
    for (int i = 0; i < 3; i++)
    {
        v[i]->mostrar();
        cout << endl;
    }
}
void ejemplo6()
{
    ModVehiculos vehiculos;
    vehiculos.registrar (new Camioneta("456", "toyota", 2020, 0, 2000));
    vehiculos.registrar (new Moto("456", "toyota", 2020, 0, "carretera"));
    vehiculos.registrar (new Camioneta("456", "toyota", 2020, 0, 2000));
    vehiculos.mostrar();
}
int main()
{
    ejemplo6();
    return 0;
}
