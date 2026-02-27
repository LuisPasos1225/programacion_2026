#ifndef COCHE_H
#define COCHE_H
#include "vehiculo.h"

class Coche : public Vehiculo {
private:
    int numeroPuertas;
public:
    Coche(std::string ma, std::string mo, int an, std::string pl, int puertas);
    void mostrarInformacion();
};
#endif