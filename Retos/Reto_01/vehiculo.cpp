#include "vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo() {
    marca = ""; modelo = ""; anio = 0; placa = "S/N";
}

Vehiculo::Vehiculo(std::string marca, std::string modelo, int anio, std::string placa) {
    this->marca = marca;
    this->modelo = modelo;
    this->anio = anio;
    this->placa = placa;
}

void Vehiculo::actualizarPlaca(std::string nuevaPlaca) {
    this->placa = nuevaPlaca;
}

void Vehiculo::mostrarInformacion() {
    std::cout << "Placa: " << placa << std::endl;
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Anio: " << anio << std::endl;
}

// Implementación de getters y setters faltantes
std::string Vehiculo::obtenerPlaca() { return placa; }
void Vehiculo::actualizarMarca(std::string m) { marca = m; }
void Vehiculo::actualizarModelo(std::string m) { modelo = m; }
void Vehiculo::actualizarAnio(int a) { anio = a; }