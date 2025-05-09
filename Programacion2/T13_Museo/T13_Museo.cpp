/*
* Un museo desea una aplicaci�n para administrar las exposiciones que realiza en sus salones.
La aplicaci�n debe permitir al usuario:
� Registrar exposiciones.
� Registrar artistas.
� Registrar obras.

Artista = nombre
HIJAS (pinto (especialidad), escultor (materiales))
Obra = titulo, precio
HIJAS (pintura (alto,ancho), escultura (peso))
*/

#include "Museo.h"
int pregunta1()

{
	cout << "----Pregunta 1----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"numero\":1,\"artistas\":[{\"nombre\":\"Juan\",\"especialidad\":\"Oleo\",\"obras\":[]},{\"nombre\":\"Jose\",\"materiales\":\"Madera\",\"obras\":[]},{\"nombre\":\"Maria\",\"materiales\":\"Arcilla\",\"obras\":[]}]}" << endl;
	// crear exposicion(numero de exposicion)
	Exposicion exposicion(1);
	// registramos pintor en exposicion(nombre artista, especialidad)
	exposicion.registrar(new Pintor("Juan", "Oleo"));
	// registramos escultor en exposicion(nombre artista, materiales)
	exposicion.registrar(new Escultor("Jose", "Madera"));
	exposicion.registrar(new Escultor("Maria", "Arcilla"));
	cout << "Resultado obtenido:" << endl;
	cout << exposicion.toJson() << endl;
	if (exposicion.toJson() == "{\"numero\":1,\"artistas\":[{\"nombre\":\"Juan\",\"especialidad\":\"Oleo\",\"obras\":[]},{\"nombre\":\"Jose\",\"materiales\":\"Madera\",\"obras\":[]},{\"nombre\":\"Maria\",\"materiales\":\"Arcilla\",\"obras\":[]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 30;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()

{
	cout << "----Pregunta 2----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"numero\":1,\"artistas\":[{\"nombre\":\"Amadeo\",\"especialidad\":\"oleo y acuarela\",\"obras\":[{\"nombre\":\"Calle\",\"precio\":2000,\"alto\":60,\"ancho\":80},{\"nombre\":\"Porton\",\"precio\":2000,\"alto\":60,\"ancho\":80}]},{\"nombre\":\"Adalberto\",\"materiales\":\"madera y hierro\",\"obras\":[{\"nombre\":\"Signos\",\"precio\":2000,\"peso\":30},{\"nombre\":\"Hombre\",\"precio\":2000,\"peso\":45}]}]}" << endl;
	// crear exposicion(numero de exposicion)
	Exposicion exposicion(1);
	// crear pintor en exposicion(nombre artista, especialidad)
	Artista* a1 = new Pintor("Amadeo", "oleo y acuarela");
	// registrar pinturas(titulo,precio,alto,ancho)
	a1->registrar(new Pintura("Calle", 2000, 60, 80));
	a1->registrar(new Pintura("Porton", 2000, 60, 80));
	// registrar artista
	exposicion.registrar(a1);
	// crear escultor en exposicion(nombre artista, especialidad)
	Artista* a2 = new Escultor("Adalberto", "madera y hierro");
	// registrar esculturas(titulo,precio,peso)
	a2->registrar(new Escultura("Signos", 2000, 30));
	a2->registrar(new Escultura("Hombre", 2000, 45));
	// registrar artista
	exposicion.registrar(a2);
	cout << "Resultado obtenido:" << endl;
	cout << exposicion.toJson() << endl;
	if (exposicion.toJson() == "{\"numero\":1,\"artistas\":[{\"nombre\":\"Amadeo\",\"especialidad\":\"oleo y acuarela\",\"obras\":[{\"nombre\":\"Calle\",\"precio\":2000,\"alto\":60,\"ancho\":80},{\"nombre\":\"Porton\",\"precio\":2000,\"alto\":60,\"ancho\":80}]},{\"nombre\":\"Adalberto\",\"materiales\":\"madera y hierro\",\"obras\":[{\"nombre\":\"Signos\",\"precio\":2000,\"peso\":30},{\"nombre\":\"Hombre\",\"precio\":2000,\"peso\":45}]}]}")
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
	cout << "Resultado esperado:" << endl;
	cout << "{\"nombre\":\"x\",\"dirreccion\":\"calle y\",\"exposiciones\":[{\"numero\":1,\"artistas\":[{\"nombre\":\"Amadeo\",\"especialidad\":\"oleo y acuarela\",\"obras\":[{\"nombre\":\"Calle\",\"precio\":2000,\"alto\":60,\"ancho\":80},{\"nombre\":\"Porton\",\"precio\":2000,\"alto\":60,\"ancho\":80}]}]},{\"numero\":2,\"artistas\":[{\"nombre\":\"Adalberto\",\"materiales\":\"madera y hierro\",\"obras\":[{\"nombre\":\"Signos\",\"precio\":2000,\"peso\":30},{\"nombre\":\"Hombre\",\"precio\":2000,\"peso\":45}]}]}]}" << endl;
	// crear museo(nombre, direccion)
	Museo museo("x", "calle y");
	// registrar exposicion(numero exposicion)
	museo.registrarExposicion(1);
	museo.registrarExposicion(2);
	// registrar artista en exposicion
	museo.registrarArtistaEnExposicion(1, new Pintor("Amadeo", "oleo y acuarela"));
	museo.registrarArtistaEnExposicion(2, new Escultor("Adalberto", "madera y hierro"));
	// registrar obra en artista(numero exposicion, nombre artista, obra)
	museo.registrarObraEnExposicion(2, "Adalberto", new Escultura("Signos", 2000, 30));
	museo.registrarObraEnExposicion(1, "Amadeo", new Pintura("Calle", 2000, 60, 80));
	museo.registrarObraEnExposicion(2, "Adalberto", new Escultura("Hombre", 2000, 45));
	museo.registrarObraEnExposicion(1, "Amadeo", new Pintura("Porton", 2000, 60, 80));
	cout << "Resultado obtenido:" << endl;
	cout << museo.toJson() << endl;
	if (museo.toJson() == "{\"nombre\":\"x\",\"dirreccion\":\"calle y\",\"exposiciones\":[{\"numero\":1,\"artistas\":[{\"nombre\":\"Amadeo\",\"especialidad\":\"oleo y acuarela\",\"obras\":[{\"nombre\":\"Calle\",\"precio\":2000,\"alto\":60,\"ancho\":80},{\"nombre\":\"Porton\",\"precio\":2000,\"alto\":60,\"ancho\":80}]}]},{\"numero\":2,\"artistas\":[{\"nombre\":\"Adalberto\",\"materiales\":\"madera y hierro\",\"obras\":[{\"nombre\":\"Signos\",\"precio\":2000,\"peso\":30},{\"nombre\":\"Hombre\",\"precio\":2000,\"peso\":45}]}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 40;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()

{
	int nota = pregunta1() + pregunta2() + pregunta3();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}