#include <iostream>
#include <windows.h>   // Necesario para UTF-8 en Windows
#include "Estudiante.h"

int main() {

    // Forzar UTF-8 en consola de Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "=== Sistema de Gestión de Estudiante ===\n\n";

  
    Estudiante e1;
    std::cout << "Estudiante 1 (constructor por defecto):\n";
    e1.mostrarDatos();

    e1.actualizarNombre("María García López");
    e1.actualizarCodigo("EST-2024-001");
    e1.actualizarEdad(20);
    e1.actualizarPromedio(9.2);
    e1.actualizarEstado(true);

    std::cout << "\nEstudiante 1 después de actualizar:\n";
    e1.mostrarDatos();

 
    Estudiante e2("Juan Pérez Martínez", "EST-2024-002", 22, 7.5, true);
    std::cout << "\nEstudiante 2 (constructor con parámetros):\n";
    e2.mostrarDatos();

    std::cout << "\nIncrementando edad del estudiante 2:\n";
    e2.incrementarEdad();
    std::cout << "Edad: " << e2.getEdad() << " años\n";

    std::cout << "\nIntentando actualizar promedio con valor inválido:\n";
    e2.actualizarPromedio(15.0);
    std::cout << "Promedio: " << e2.getPromedio() << "\n";

    system("pause");
    return 0;
}
