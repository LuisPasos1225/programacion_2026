#include <iostream>
#include <vector>
#include "coche.h"
#include "moto.h"
#include "camion.h"
#include "autobus.h"

int main() {
    // 1. Crear objetos de las distintas clases
    Coche miCoche("Toyota", "Corolla", 2022, "ABC-123", 4);
    Moto miMoto("Yamaha", "MT-07", 2023, "MOT-99", false);
    Camion miCamion("Volvo", "FH16", 2020, "TRK-500", 25.5);

    std::cout << "--- ESTADO INICIAL ---" << std::endl;
    miCoche.mostrarInformacion();
    miMoto.mostrarInformacion();

    // 2. Gestionar cambio de placas solicitado por el reto
    std::string nuevaPlaca;
    
    std::cout << "\n--- PROCESO DE CAMBIO DE PLACAS ---" << std::endl;
    
    std::cout << "Ingrese la nueva placa para el coche Toyota: ";
    std::cin >> nuevaPlaca;
    miCoche.actualizarPlaca(nuevaPlaca);

    std::cout << "Ingrese la nueva placa para la moto Yamaha: ";
    std::cin >> nuevaPlaca;
    miMoto.actualizarPlaca(nuevaPlaca);


    std::cout << "\n--- ESTADO FINAL ---" << std::endl;
    miCoche.mostrarInformacion();
    miMoto.mostrarInformacion();
    miCamion.mostrarInformacion();

    return 0;
}