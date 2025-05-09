/*
Se desea un programa para simular el mapa de un video juego.
Donde existe diferentes tipos de objetos: Bloques y Personajes.
Existen dos tipos de personajes: Heroe y Villano que pueden moverse dentro
del mapa.
El sistema programa debe brindar las siguientes funcionalidades:
• Crear un mapa en base a una matriz genérica
• Registrar objetos(personajes o bloques)
• Registrar movimientos de los personajes
*/

#include "Juego.h"

//Creamos el juego(alto, ancho)
Juego juego(5, 5);

int pregunta1()
{
    cout << "----Pregunta 1----" << endl;
    string error;
    //Creamos una matriz que representa el mapa del juego
    Matriz<Objeto*> mapa(5, 5);
    try {
        //Creamos personajes (id, x, y)
        Personaje* per1 = new Heroe(1, 1, 1);
        Personaje* per2 = new Villano(2, 2, 2);
        //Creamos bloques (id, x, y)
        Bloque* b1 = new Bloque(3, 3, 3);
        Bloque* b2 = new Bloque(4, 3, 4);

        //Colocamos objetos en el mapa
        mapa[1][1] = per1;
        mapa[2][2] = per2;
        mapa[3][3] = b1;
        mapa[4][3] = b2;
    }
    catch (exception& e) {
        error = e.what();
    }
    string result = mapa.toString(Objeto::toStatic);
    cout << "esperado" << endl;
    cout << "{0}{0}{0}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n" << endl;
    cout << "obtenido" << endl;
    cout << result << endl;

    cout << error << endl;
    if (error == "" && result == "{0}{0}{0}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n")
    {
        cout << "Resultado: correcto" << endl;
        return 20;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}
int pregunta2()
{
    cout << "----Pregunta 2----" << endl;
    string error;
    try {
        //Creamos personajes en el juego
        juego.agregar(new Heroe(1, 1, 1));
        juego.agregar(new Villano(2, 2, 2));
        juego.agregar(new Bloque(3, 3, 3));
        juego.agregar(new Bloque(4, 4, 3));
    }
    catch (exception& e) {
        error = e.what();
    }
    string result = juego.getMapa();
    cout << "esperado" << endl;
    cout << "{0}{0}{0}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n" << endl;
    cout << "obtenido" << endl;
    cout << result << endl;
    if (error == "" && result == "{0}{0}{0}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n")
    {
        cout << "Resultado: correcto" << endl;
        return 30;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta3()
{
    cout << "----Pregunta 3----" << endl;
    string error;
    try {
        //movemos a heroe(id,x,y)
        juego.mover(1, 2, 1);
        //movemos a villano(id,x,y)
        juego.mover(2, 1, 2);
        //intentamos mover un bloque(error)
        juego.mover(3, 4, 3);
    }
    catch (exception& e) {
        error = e.what();
    }
    string result = juego.getMapa();
    cout << "esperado" << endl;
    cout << "el objeto no puede moverse" << endl;
    cout << "{0}{0}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n" << endl;
    cout << "obtenido" << endl;
    cout << error << endl;
    cout << result << endl;
    if (error == "el objeto no puede moverse" && result == "{0}{0}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n")
    {
        cout << "Resultado: correcto" << endl;
        return 50;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int pregunta4()
{
    cout << "----Pregunta 4----" << endl;
    string error;
    try {
        //movemos a heroe a una casilla ocupada(error)
        juego.mover(1, 1, 2);
    }
    catch (exception& e) {
        error = e.what();
    }
    string result = juego.getMapa();
    cout << result << endl;
    cout << error << endl;
    if (error == "casilla ocupada" && result == "{0}{0}{0}{0}{0}\n"
        "{0}{0}{V:{id:2,x:2,y:2}}{0}{0}\n"
        "{0}{H:{id:1,x:1,y:1}}{0}{0}{0}\n"
        "{0}{0}{0}{|}{0}\n"
        "{0}{0}{0}{|}{0}\n")
    {
        cout << "Resultado: correcto" << endl;
        return 10;
    }
    cout << "Resultado: incorrecto" << endl;
    return 0;
}

int main()
{
    int nota = pregunta1() + pregunta2() + pregunta3() +pregunta4();
    cout << endl;
    cout << "====================" << endl;
    cout << "===> NOTA: " << nota << "/100" << endl;
    cout << "====================" << endl;
    system("pause");
    return 0;
}