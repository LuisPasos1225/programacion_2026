#include "libro.h"
#include <iostream>

Libro::Libro() {
    nombre = "";
    codigo = "";
    prestado = false;
}

Libro::Libro(std::string nombre, std::string codigo, bool prestado) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->prestado = prestado;
}


void Libro::actualizarNombre(std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Libro::actualizarCodigo(std::string nuevoCodigo) {
    codigo = nuevoCodigo;
}

void Libro::actualizarPrestado(bool nuevoEstado) {
    prestado = nuevoEstado;
}

void Libro::mostrarNombre() {
    std::cout << "Nombre del libro: " << nombre << std::endl;
}

void Libro::mostrarCodigo() {
    std::cout << "Código del libro: " << codigo << std::endl;
}

void Libro::mostrarPrestado() {
    if (prestado) {
        std::cout << "Estado: Prestado" << std::endl;
    } else {
        std::cout << "Estado: Disponible" << std::endl;
    }
}

// Getters
std::string Libro::obtenerNombre() {
    return nombre;
}

std::string Libro::obtenerCodigo() {
    return codigo;
}

bool Libro::obtenerPrestado() {
    return prestado;
}
