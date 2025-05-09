//Whatsapp es una aplicación de mensajeria instantánea que permite a sus usuarios
//intercambiar mensajes(Texto y Archivos)
//con sus contactos y grupos.

#include "Whatsapp.h"
int pregunta0()
{
	cout << "----Pregunta 0----" << endl;
	cout << "Esperado"<<endl;
	cout << "{\"telefono\":70700001,\"nombre\":\"Paola\",\"chats\":[{\"telefono\":70700002,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]},{\"telefono\":70700003,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]}" << endl;

	//Creamos usuarios(telefono,nombre)
	Usuario* paola = new Usuario(70700001, "Paola");
	Usuario* leonardo = new Usuario(70700002, "Leonardo");
	Usuario* elena = new Usuario(70700003, "Elena");
	// Paola envia mensaje a Leonardo
	Mensaje* m1 = new Texto(70700001, "Mandame la foto");
	paola->enviarMensaje(m1, 70700002);
	leonardo->recibirMensaje(m1);
	// Leonardo envia mensaje a Paola
	Mensaje* m2 = new Archivo(70700002, "Familia", "jpg");
	leonardo->enviarMensaje(m2, 70700001);
	paola->recibirMensaje(m2);
	// Paola envia mensaje a Elena
	Mensaje* m3 = new Texto(70700001, "Como estas?");
	paola->enviarMensaje(m3, 70700003);
	elena->recibirMensaje(m3);
	cout << "Obtenido" << endl;
	cout << paola->toString() << endl;

	if (paola->toString() == "{\"telefono\":70700001,\"nombre\":\"Paola\",\"chats\":[{\"telefono\":70700002,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]},{\"telefono\":70700003,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Esperado" << endl;
	cout << "{\"telefono\":70700001,\"nombre\":\"Paola\",\"chats\":[{\"telefono\":70700002,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]},{\"telefono\":70700003,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]}"<<endl;
	//Creamos el objeto whatsapp
	Whatsapp whatsapp;
	// Registramos usuarios (telefono, nombre)
	whatsapp.registrarUsuario(70700001, "Paola");
	whatsapp.registrarUsuario(70700002, "Leonardo");
	whatsapp.registrarUsuario(70700003, "Elena");
	// Paola envia mensaje a Leonardo
	whatsapp.enviarMensaje(new Texto(70700001, "Mandame la foto"), 70700002);
	// Leonardo envia mensaje a Paola
	whatsapp.enviarMensaje(new Archivo(70700002, "Familia", "jpg"), 70700001);
	// Paola envia mensaje a Elena
	whatsapp.enviarMensaje(new Texto(70700001, "Como estas?"), 70700003);

	cout << "Obtenido" << endl;
	cout << whatsapp.getUsuario(70700001)->toString() << endl;

	if (whatsapp.getUsuario(70700001)->toString() == "{\"telefono\":70700001,\"nombre\":\"Paola\",\"chats\":[{\"telefono\":70700002,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]},{\"telefono\":70700003,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]}")
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
	cout << "Esperado" << endl;
	cout << "{\"usuarios\":[{\"telefono\":70700003,\"nombre\":\"Elena\",\"chats\":[{\"telefono\":70700001,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]},{\"telefono\":70700002,\"nombre\":\"Leonardo\",\"chats\":[{\"telefono\":70700001,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]}]},{\"telefono\":70700001,\"nombre\":\"Paola\",\"chats\":[{\"telefono\":70700002,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]},{\"telefono\":70700003,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]}]}" << endl;
	//Creamos el objeto whatsapp
	Whatsapp whatsapp;
	// Registramos usuarios (telefono, nombre)
	whatsapp.registrarUsuario(70700001, "Paola");
	whatsapp.registrarUsuario(70700002, "Leonardo");
	whatsapp.registrarUsuario(70700003, "Elena");
	// Paola envia mensaje a Leonardo
	whatsapp.enviarMensaje(new Texto(70700001, "Mandame la foto"), 70700002);
	// Leonardo envia mensaje a Paola
	whatsapp.enviarMensaje(new Archivo(70700002, "Familia", "jpg"), 70700001);
	// Paola envia mensaje a Elena
	whatsapp.enviarMensaje(new Texto(70700001, "Como estas?"), 70700003);
	cout << "Obtenido" << endl;
	cout << whatsapp.usuariosToString() << endl;

	if (whatsapp.usuariosToString() == "{\"usuarios\":[{\"telefono\":70700003,\"nombre\":\"Elena\",\"chats\":[{\"telefono\":70700001,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]},{\"telefono\":70700002,\"nombre\":\"Leonardo\",\"chats\":[{\"telefono\":70700001,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]}]},{\"telefono\":70700001,\"nombre\":\"Paola\",\"chats\":[{\"telefono\":70700002,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Mandame la foto\"},{\"autor\":70700002,\"tipo\":\"archivo\",\"nombre\":\"Familia\",\"ext\":\"jpg\"}]},{\"telefono\":70700003,\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Como estas?\"}]}]}]}")
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
	cout << "Esperado" << endl;
	cout << "{\"grupos\":[{\"nombre\":\"Paola y Leonardo\",\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Hola, como estas?\"},{\"autor\":70700002,\"tipo\":\"texto\",\"contenido\":\"Bien gracias, tu?\"},{\"autor\":70700001,\"tipo\":\"archivo\",\"nombre\":\"Sonrisa\",\"ext\":\"jpg\"}],\"usuarios\":[{\"telefono\":70700001,\"nombre\":\"Paola\"},{\"telefono\":70700002,\"nombre\":\"Leonardo\"}]},{\"nombre\":\"Paola y Elena\",\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Que haces?\"},{\"autor\":70700003,\"tipo\":\"texto\",\"contenido\":\"Nada, tu?\"},{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Nada.\"}],\"usuarios\":[{\"telefono\":70700001,\"nombre\":\"Paola\"},{\"telefono\":70700003,\"nombre\":\"Elena\"}]}]}" << endl;
	//Creamos el objeto whatsapp
	Whatsapp whatsapp;
	// Registramos usuarios (telefono, nombre)
	whatsapp.registrarUsuario(70700001, "Paola");
	whatsapp.registrarUsuario(70700002, "Leonardo");
	whatsapp.registrarUsuario(70700003, "Elena");
	// Creamos el grupo de Paola y Leonardo
	whatsapp.crearGrupo("Paola y Leonardo");
	whatsapp.agregarParticipante(70700001, "Paola y Leonardo");
	whatsapp.agregarParticipante(70700002, "Paola y Leonardo");
	// Creamos el grupo de Paola y Elena
	whatsapp.crearGrupo("Paola y Elena");
	whatsapp.agregarParticipante(70700001, "Paola y Elena");
	whatsapp.agregarParticipante(70700003, "Paola y Elena");
	// Paola y Leonardo envian mensajes
	whatsapp.enviarMensaje("Paola y Leonardo", new Texto(70700001, "Hola, como estas?"));
	whatsapp.enviarMensaje("Paola y Leonardo", new Texto(70700002, "Bien gracias, tu?"));
	whatsapp.enviarMensaje("Paola y Leonardo", new Archivo(70700001, "Sonrisa", "jpg"));
	// Paola y Elena envian mensajes
	whatsapp.enviarMensaje("Paola y Elena", new Texto(70700001, "Que haces?"));
	whatsapp.enviarMensaje("Paola y Elena", new Texto(70700003, "Nada, tu?"));
	whatsapp.enviarMensaje("Paola y Elena", new Texto(70700001, "Nada."));
	cout << "Obtenido" << endl;
	cout << whatsapp.gruposToString() << endl;

	if (whatsapp.gruposToString() == "{\"grupos\":[{\"nombre\":\"Paola y Leonardo\",\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Hola, como estas?\"},{\"autor\":70700002,\"tipo\":\"texto\",\"contenido\":\"Bien gracias, tu?\"},{\"autor\":70700001,\"tipo\":\"archivo\",\"nombre\":\"Sonrisa\",\"ext\":\"jpg\"}],\"usuarios\":[{\"telefono\":70700001,\"nombre\":\"Paola\"},{\"telefono\":70700002,\"nombre\":\"Leonardo\"}]},{\"nombre\":\"Paola y Elena\",\"mensajes\":[{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Que haces?\"},{\"autor\":70700003,\"tipo\":\"texto\",\"contenido\":\"Nada, tu?\"},{\"autor\":70700001,\"tipo\":\"texto\",\"contenido\":\"Nada.\"}],\"usuarios\":[{\"telefono\":70700001,\"nombre\":\"Paola\"},{\"telefono\":70700003,\"nombre\":\"Elena\"}]}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta0() + pregunta1() + pregunta2() + pregunta3();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}