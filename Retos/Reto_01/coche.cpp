#include "coche.h"
#include <iostream>

Coche::Coche(std::string ma, std::string mo, int an, std::string pl, int puertas)
    : Vehiculo(ma, mo, an, pl), numeroPuertas(puertas) {}

void Coche::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Puertas: " << numeroPuertas << std::endl;
}