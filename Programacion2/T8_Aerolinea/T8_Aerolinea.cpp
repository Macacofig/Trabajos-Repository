/*
* Una aerolÌnea, desea un sistema inform·tico para el control de vuelos que ofrece a su clientela.
El sistema debe permitir realizar las siguientes operaciones:
- Registrar clientes
- Registrar aviones
- Registrar vuelos
- Agregar un pasajero a un vuelo de pasajeros existente

*/
#include "Aerolinea.h"
int pregunta1()
{
    cout << "----Pregunta 1----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":4,\"columnas\":2},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":3,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":3,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":4,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":4,\"columna\":2,\"pasajero\":\"vacio\"}]}" << endl;
    // Creamos un avion(placa, numero de filas y columnas de asientos)
    Avion* avion = new Avion(12345, 4, 2);
    // Creamos un vuelo (numero, avion)
    Vuelo* vuelo = new Vuelo(1, avion);
    cout << "Resultado obtenido:" << endl;
    cout << vuelo->toJson() << endl;
    if (vuelo->toJson() == "{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":4,\"columnas\":2},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":3,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":3,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":4,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":4,\"columna\":2,\"pasajero\":\"vacio\"}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta2()
{
    cout << "----Pregunta 2----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":2,\"columnas\":3},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":3,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777}},{\"fila\":2,\"columna\":3,\"pasajero\":\"vacio\"}]}" << endl;
    // Creamos un avion(placa, numero de filas y columnas de asientos)
    Avion* avion = new Avion(12345, 2, 3);
    // Creamos un vuelo (numero, avion)
    Vuelo vuelo(1, avion);
    // Registramos pasajero en vuelo(fila, columna, Persona)
    vuelo.registrarPasajero(2, 2, new Persona(1000, "juan", "calle x", 7777777));
    cout << "Resultado obtenido:" << endl;
    cout << vuelo.toJson() << endl;
    if (vuelo.toJson() == "{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":2,\"columnas\":3},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":3,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777}},{\"fila\":2,\"columna\":3,\"pasajero\":\"vacio\"}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta3()
{
    cout << "----Pregunta 3----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":2,\"columnas\":3},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":{\"ci\":1001,\"nombre\":\"pedro\",\"direccion\":\"calle y\",\"fono\":7777771}},{\"fila\":1,\"columna\":3,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777}},{\"fila\":2,\"columna\":3,\"pasajero\":\"vacio\"}]}" << endl;
    // Creamos un avion(placa, numero de filas y columnas de asientos)
    Avion* avion = new Avion(12345, 2, 3);
    // Creamos un vuelo (numero, avion)
    Vuelo vuelo(1, avion);
    // Registramos pasajero en vuelo(fila, columna, Persona)
    vuelo.registrarPasajero(1, 2, new Persona(1000, "juan", "calle x", 7777777));
    vuelo.registrarPasajero(2, 2, new Persona(1001, "pedro", "calle y", 7777771));
    // Los pasajeros intercambian asientos(fila1, columna1, fila2, columna2)
    vuelo.intercambiarAsiento(new Asiento(1, 2), new Asiento(2, 2));
    cout << "Resultado obtenido:" << endl;
    cout << vuelo.toJson() << endl;
    if (vuelo.toJson() == "{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":2,\"columnas\":3},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":{\"ci\":1001,\"nombre\":\"pedro\",\"direccion\":\"calle y\",\"fono\":7777771}},{\"fila\":1,\"columna\":3,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777}},{\"fila\":2,\"columna\":3,\"pasajero\":\"vacio\"}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta4()
{
    cout << "----Pregunta 4----" << endl;
    cout << "Resultado esperado:" << endl;
    cout << "{\"nombre\":\"boa\",\"clientes\":[{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777},{\"ci\":1001,\"nombre\":\"pedro\",\"direccion\":\"calle y\",\"fono\":7777771}],\"aviones\":[{\"placa\":12345,\"filas\":2,\"columnas\":3}],\"vuelos\":[{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":2,\"columnas\":3},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":{\"ci\":1001,\"nombre\":\"pedro\",\"direccion\":\"calle y\",\"fono\":7777771}},{\"fila\":1,\"columna\":3,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777}},{\"fila\":2,\"columna\":3,\"pasajero\":\"vacio\"}]}]}" << endl;
    //Creamos aerolinea(nombre, tamMaxAviones, tamMaxClientes, tamMaxVuelos)
    Aerolinea aerolinea("boa", 5, 5, 5);
    //Registramos clientes
    aerolinea.getClientes().registrar(new Persona(1000, "juan", "calle x", 7777777));
    aerolinea.getClientes().registrar(new Persona(1001, "pedro", "calle y", 7777771));
    // Creamos un avion(placa, numero de filas y columnas de asientos)
    aerolinea.getAviones().registrar(new Avion(12345, 2, 3));
    // Creamos un vuelo (numero vuelo, placa avion)

    aerolinea.registrarVuelo(1, 12345);
    // Registramos pasajero en vuelo(fila, columna, CI de la persona)
    aerolinea.registrarPasajeroEnVuelo(1, 1, 2, 1001);
    aerolinea.registrarPasajeroEnVuelo(1, 2, 2, 1000);
    cout << "Resultado obtenido:" << endl;
    cout << aerolinea.toJson() << endl;
    if (aerolinea.toJson() == "{\"nombre\":\"boa\",\"clientes\":[{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777},{\"ci\":1001,\"nombre\":\"pedro\",\"direccion\":\"calle y\",\"fono\":7777771}],\"aviones\":[{\"placa\":12345,\"filas\":2,\"columnas\":3}],\"vuelos\":[{\"numero\":1,\"avion\":{\"placa\":12345,\"filas\":2,\"columnas\":3},\"asientos\":[{\"fila\":1,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":1,\"columna\":2,\"pasajero\":{\"ci\":1001,\"nombre\":\"pedro\",\"direccion\":\"calle y\",\"fono\":7777771}},{\"fila\":1,\"columna\":3,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":1,\"pasajero\":\"vacio\"},{\"fila\":2,\"columna\":2,\"pasajero\":{\"ci\":1000,\"nombre\":\"juan\",\"direccion\":\"calle x\",\"fono\":7777777}},{\"fila\":2,\"columna\":3,\"pasajero\":\"vacio\"}]}]}")
    {
        cout << "Resultado: correcto" << endl;
        return 25;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}
int main()
{
    int nota = pregunta1() + pregunta2() + pregunta3() + pregunta4();
    cout << endl;
    cout << "====================" << endl;
    cout << "===> NOTA: " << nota << "/100" << endl;
    cout << "====================" << endl;
    system("pause");
    return 0;
}