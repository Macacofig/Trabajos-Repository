#include <iostream>
#include <string>
using namespace std;

class Bloque {
public:
    int inicio;
    int tamanio;
    bool libre;
    string proceso;
    Bloque* sig;

    Bloque(int i, int t, bool l = true, string p = "")
        : inicio(i), tamanio(t), libre(l), proceso(p), sig(nullptr) {}
};

class GestorMemoria {
private:
    Bloque* cabeza;
    int memoriaTotal;

public:
    GestorMemoria() {
        cabeza = nullptr;
        memoriaTotal = 0;
    }

    void INIT(int tam) {
        memoriaTotal = tam;
        cabeza = new Bloque(0, tam, true);
    }

    Bloque* buscarBloque(int tam, string estrategia) {
        Bloque* actual = cabeza;
        Bloque* candidato = nullptr;

        while (actual) {
            if (actual->libre && actual->tamanio >= tam) {
                if (estrategia == "FIRST")
                    return actual;

                if (estrategia == "BEST") {
                    if (!candidato || actual->tamanio < candidato->tamanio)
                        candidato = actual;
                }

                if (estrategia == "WORST") {
                    if (!candidato || actual->tamanio > candidato->tamanio)
                        candidato = actual;
                }
            }
            actual = actual->sig;
        }
        return candidato;
    }

    void ALOCAR(string id, int tam, string estrategia) {
        Bloque* bloque = buscarBloque(tam, estrategia);

        if (!bloque) {
            cout << "No hay memoria suficiente\n";
            return;
        }

        if (bloque->tamanio > tam) {
            Bloque* nuevoLibre = new Bloque(
                bloque->inicio + tam,
                bloque->tamanio - tam,
                true
            );

            nuevoLibre->sig = bloque->sig;
            bloque->sig = nuevoLibre;
        }

        bloque->tamanio = tam;
        bloque->libre = false;
        bloque->proceso = id;

        cout << id << " asignado: "
            << tam << " KB en direccion "
            << bloque->inicio << "\n";
    }

    void LIBERAR(string id) {
        Bloque* actual = cabeza;

        while (actual) {
            if (!actual->libre && actual->proceso == id) {
                actual->libre = true;
                actual->proceso = "";
                cout << id << " liberado: "
                    << actual->tamanio << " KB\n";
                return;
            }
            actual = actual->sig;
        }
        cout << "Proceso no encontrado\n";
    }

    void COMPACTAR() {
        Bloque* actual = cabeza;
        int libresUnidos = 1;

        while (actual && actual->sig) {
            if (actual->libre && actual->sig->libre) {
                actual->tamanio += actual->sig->tamanio;
                Bloque* temp = actual->sig;
                actual->sig = temp->sig;
                delete temp;
                libresUnidos++;
            }
            else {
                actual = actual->sig;
            }
        }

        cout << "Memoria compactada: "
            << libresUnidos
            << " bloques libres unidos\n";
    }

    void ESTADO() {
        Bloque* actual = cabeza;
        cout << "Mapa de memoria:\n";

        while (actual) {
            cout << "["
                << actual->inicio
                << "-"
                << actual->inicio + actual->tamanio
                << "]: ";

            if (actual->libre)
                cout << "LIBRE";
            else
                cout << actual->proceso;

            cout << " ("
                << actual->tamanio
                << " KB)\n";

            actual = actual->sig;
        }
    }
};

int main() {
    GestorMemoria gm;

    /*
    INIT 1024
    ALOCAR P1 200 FIRST
    ALOCAR P2 300 FIRST
    ALOCAR P3 100 FIRST
    ALOCAR P4 150 FIRST
    ESTADO

    LIBERAR P2
    LIBERAR P4
    ESTADO

    ALOCAR P5 120 BEST
    ESTADO

    ALOCAR P6 120 WORST
    ESTADO

    COMPACTAR
    ESTADO
    */
    gm.INIT(1024);
    gm.ALOCAR("P1", 200, "FIRST");
    gm.ALOCAR("P2", 300, "FIRST");
    gm.ALOCAR("P3", 100, "FIRST");
    gm.ALOCAR("P4", 150, "FIRST");
    gm.ESTADO();

    gm.LIBERAR("P2");
    gm.LIBERAR("P4");
    gm.ESTADO();

    gm.ALOCAR("P5", 120, "BEST");
    gm.ESTADO();

    gm.ALOCAR("P6", 120, "WORST");
    gm.ESTADO();

    gm.COMPACTAR();
    gm.ESTADO();
    return 0;
}
