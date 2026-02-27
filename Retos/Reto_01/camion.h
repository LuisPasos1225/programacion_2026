#ifndef CAMION_H
#define CAMION_H
#include "vehiculo.h"

class Camion : public Vehiculo {
private:
    double capacidadCarga;
public:
    Camion(std::string ma, std::string mo, int an, std::string pl, double carga) 
        : Vehiculo(ma, mo, an, pl), capacidadCarga(carga) {}

    void mostrarInformacion() {
        Vehiculo::mostrarInformacion();
        std::cout << "Capacidad de carga: " << capacidadCarga << " toneladas" << std::endl;
    }
};
#endif