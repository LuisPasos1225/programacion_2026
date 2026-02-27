#ifndef AUTOBUS_H
#define AUTOBUS_H
#include "vehiculo.h"

class Autobus : public Vehiculo {
private:
    int capacidadPasajeros;
public:
    Autobus(std::string ma, std::string mo, int an, std::string pl, int pasajeros) 
        : Vehiculo(ma, mo, an, pl), capacidadPasajeros(pasajeros) {}

    void mostrarInformacion() {
        Vehiculo::mostrarInformacion();
        std::cout << "Capacidad de pasajeros: " << capacidadPasajeros << std::endl;
    }
};
#endif