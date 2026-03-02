#ifndef MOTO_H
#define MOTO_H
#include "vehiculo.h"

class Moto : public Vehiculo {
private:
    bool tieneSidecar;
public:
    Moto(std::string ma, std::string mo, int an, std::string pl, bool sidecar);
    void mostrarInformacion() override;
};
#endif