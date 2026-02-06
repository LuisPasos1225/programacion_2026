#include <iostream>
#include <windows.h>   // 👈 necesario en Windows
#include "libro.h"

int main() {
 
    // Fuerza UTF-8 en consola de Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "=== Ejemplo de uso de la clase Libro ===\n\n";

    Libro libro1;
    std::cout << "Libro 1 (constructor por defecto):\n";
    libro1.mostrarNombre();
    libro1.mostrarCodigo();
    libro1.mostrarPrestado();
    std::cout << std::endl;

    libro1.actualizarNombre("Cien años de soledad");
    libro1.actualizarCodigo("LIB-001");
    libro1.actualizarPrestado(true);

    std::cout << "Libro 1 después de actualizar:\n";
    libro1.mostrarNombre();
    libro1.mostrarCodigo();
    libro1.mostrarPrestado();
    std::cout << std::endl;

    Libro libro2("El Quijote", "LIB-002", false);
    std::cout << "Libro 2 (constructor con parámetros):\n";
    libro2.mostrarNombre();
    libro2.mostrarCodigo();
    libro2.mostrarPrestado();
    std::cout << std::endl;

    libro2.actualizarPrestado(true);
    std::cout << "Libro 2 después de prestarlo:\n";
    libro2.mostrarNombre();
    libro2.mostrarCodigo();
    libro2.mostrarPrestado();
    std::cout << std::endl;

    libro2.actualizarNombre("Don Quijote de la Mancha");
    std::cout << "Libro 2 con nombre actualizado:\n";
    libro2.mostrarNombre();
    libro2.mostrarCodigo();
    libro2.mostrarPrestado();
    std::cout << std::endl;

    Libro libro3("1984", "LIB-003", false);
    std::cout << "Libro 3:\n";
    libro3.mostrarNombre();
    libro3.mostrarCodigo();
    libro3.mostrarPrestado();

    std::cout << std::endl;
    system("pause");

    return 0;
}
