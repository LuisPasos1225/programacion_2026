#include "vehiculo.h"

class Moto : public Vehiculo {
private:
    bool tieneSidecar;
public:
    Moto(std::string ma, std::string mo, int an, std::string pl, bool sidecar) 
        : Vehiculo(ma, mo, an, pl), tieneSidecar(sidecar) {}

    void mostrarInformacion() {
        Vehiculo::mostrarInformacion();
        std::cout << "Tiene sidecar: " << (tieneSidecar ? "Sí" : "No") << std::endl;
    }
};
