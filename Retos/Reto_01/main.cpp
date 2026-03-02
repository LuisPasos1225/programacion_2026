#include <iostream>
#include <string>
#include "coche.h"
#include "moto.h"
#include "camion.h"
#include "autobus.h"

int main() {
   
    Coche miCoche("Toyota", "Corolla", 2022, "ABC-123", 4);
    Moto miMoto("Yamaha", "MT-07", 2023, "MOT-99", false);
    Camion miCamion("Volvo", "FH16", 2020, "TRK-500", 25.5);
    Autobus miAutobus("Mercedes", "O500", 2021, "BUS-77", 40);

    std::string accion;
    std::string vehiculo;
    std::string nuevaPlaca;

    while (true) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "¿Que quieres hacer? (MostrarInformacion, CambiarPlacas, Salir): ";
        std::cin >> accion;

        if (accion == "Salir" || accion == "salir") break;

        
        if (accion == "MostrarInformacion" || accion == "mostrar") {
            std::cout << "¿De que quieres ver informacion? (Coche, Moto, Camion, Autobus, Todos): ";
            std::cin >> vehiculo;

            if (vehiculo == "Coche" || vehiculo == "coche") miCoche.mostrarInformacion();
            else if (vehiculo == "Moto" || vehiculo == "moto") miMoto.mostrarInformacion();
            else if (vehiculo == "Camion" || vehiculo == "camion") miCamion.mostrarInformacion();
            else if (vehiculo == "Autobus" || vehiculo == "autobus") miAutobus.mostrarInformacion();
            else if (vehiculo == "Todos" || vehiculo == "todos") {
                miCoche.mostrarInformacion();
                miMoto.mostrarInformacion();
                miCamion.mostrarInformacion();
                miAutobus.mostrarInformacion();
            }
        }
      
        else if (accion == "CambiarPlacas" || accion == "cambiar") {
            std::cout << "¿De que vehiculo quieres cambiar placas? (Coche, Moto, Camion, Autobus): ";
            std::cin >> vehiculo;

            std::cout << "Ingresa la nueva placa: ";
            std::cin >> nuevaPlaca;

            if (vehiculo == "Coche" || vehiculo == "coche") {
                miCoche.actualizarPlaca(nuevaPlaca);
                std::cout << "Placa de Coche actualizada." << std::endl;
            } 
            else if (vehiculo == "Moto" || vehiculo == "moto") {
                miMoto.actualizarPlaca(nuevaPlaca);
                std::cout << "Placa de Moto actualizada." << std::endl;
            }
            else if (vehiculo == "Camion" || vehiculo == "camion") {
                miCamion.actualizarPlaca(nuevaPlaca);
                std::cout << "Placa de Camion actualizada." << std::endl;
            }
            else if (vehiculo == "Autobus" || vehiculo == "autobus") {
                miAutobus.actualizarPlaca(nuevaPlaca);
                std::cout << "Placa de Autobus actualizada." << std::endl;
            }
        } 
        else {
            std::cout << "Accion no reconocida." << std::endl;
        }
    }

    std::cout << "Cerrando sistema de gestion..." << std::endl;
    return 0;
}