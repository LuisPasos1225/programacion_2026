#include "empleado.h"
#include <iostream>

// Constructor por defecto
Empleado::Empleado() : nombre(""), id(""), salarioBase(0.0) {}

// Constructor con parámetros
Empleado::Empleado(std::string nombre, std::string id, float salarioBase)
    : nombre(nombre), id(id), salarioBase(salarioBase) {}

// Setters
void Empleado::actualizarNombre(std::string nombre) { this->nombre = nombre; }
void Empleado::actualizarId(std::string id) { this->id = id; }
void Empleado::actualizarSalarioBase(float salarioBase) { this->salarioBase = salarioBase; }

// Getters
std::string Empleado::obtenerNombre() const { return nombre; }
std::string Empleado::obtenerId() const { return id; }
float Empleado::obtenerSalarioBase() const { return salarioBase; }

// Mostrar información
void Empleado::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Salario base: " << salarioBase << std::endl;
}