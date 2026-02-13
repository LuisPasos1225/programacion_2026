#ifndef CELULAR_H
#define CELULAR_H

#include <string>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    double precio;
    int bateria;
    bool encendido;

public:
    Celular(string marca, string modelo, double precio);
    void encender();
    void apagar();
    void mostrarInfo();
};

#endif