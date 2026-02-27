#include "moto.h"
#include <iostream>

// Asumiendo que tu moto.h tiene un constructor similar
Moto::Moto(std::string ma, std::string mo, int an, std::string pl, bool sidecar)
    : Vehiculo(ma, mo, an, pl), tieneSidecar(sidecar) {}

void Moto::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Tiene sidecar: " << (tieneSidecar ? "Si" : "No") << std::endl;
}