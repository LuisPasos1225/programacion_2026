#include "celular.h"
#include <iostream>
using namespace std;

Celular::Celular(string marca, string modelo, double precio) {
    this->marca = marca;
    this->modelo = modelo;
    this->precio = precio;
    this->bateria = 100;
    this->encendido = false;
}

void Celular::encender() {
    encendido = true;
    cout << "Celular encendido\n";
}

void Celular::apagar() {
    encendido = false;
    cout << "Celular apagado\n";
}

void Celular::mostrarInfo() {
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Bateria: " << bateria << "%\n";
}