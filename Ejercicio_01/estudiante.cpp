#include <iostream>
#include "Estudiante.h"


Estudiante::Estudiante() {
    nombre = "";
    codigo = "";
    edad = 0;
    promedio = 0.0;
    activo = false;
}

Estudiante::Estudiante(std::string nombre, std::string codigo, int edad, double promedio, bool activo) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->edad = edad;
    this->promedio = promedio;
    this->activo = activo;
}


void Estudiante::actualizarNombre(std::string nombre) {
    this->nombre = nombre;
}

void Estudiante::actualizarCodigo(std::string codigo) {
    this->codigo = codigo;
}

void Estudiante::actualizarEdad(int edad) {
    if (edad >= 0) {
        this->edad = edad;
    }
}

void Estudiante::actualizarPromedio(double promedio) {
    if (promedio >= 0.0 && promedio <= 10.0) {
        this->promedio = promedio;
    } else {
        std::cout << "Error: El promedio debe estar entre 0.0 y 10.0\n";
    }
}

void Estudiante::actualizarEstado(bool activo) {
    this->activo = activo;
}

void Estudiante::incrementarEdad() {
    edad++;
}


int Estudiante::getEdad() const {
    return edad;
}

double Estudiante::getPromedio() const {
    return promedio;
}


std::string Estudiante::estadoAcademico() const {
    if (promedio >= 9.0) return "Excelente";
    if (promedio >= 7.0) return "Bueno";
    if (promedio >= 6.0) return "Suficiente";
    return "Insuficiente";
}


void Estudiante::mostrarDatos() const {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Código: " << codigo << "\n";
    std::cout << "Edad: " << edad << " años\n";
    std::cout << "Promedio: " << promedio << "\n";
    std::cout << "Estado: " << (activo ? "Activo" : "Inactivo") << "\n";

    if (activo) {
        std::cout << "Estado académico: " << estadoAcademico() << "\n";
    }
}
