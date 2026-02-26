#include <iostream>
#include <windows.h>   // Para manipular la configuración de la consola
#include <locale>      // Para configurar la locale
#include "empleado_tiempo_completo.h"

int main() {
    // Forzar UTF-8 en entrada y salida de la consola
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Configurar locale global a UTF-8
    std::locale::global(std::locale(".UTF-8"));
    std::cout.imbue(std::locale());

    std::cout << "=== Sistema de Gestión de Empleados ===" << std::endl << std::endl;

    // Empleado (solo clase base)
    Empleado emp1("Ana López", "EMP-001", 15000.0);
    std::cout << "Empleado (clase base):" << std::endl;
    emp1.mostrarInformacion();
    std::cout << std::endl;

    // Empleado a tiempo completo (constructor por defecto)
    EmpleadoTiempoCompleto etc1;
    std::cout << "Empleado tiempo completo (constructor por defecto):" << std::endl;
    etc1.mostrarInformacion();
    std::cout << std::endl;

    // Empleado a tiempo completo (constructor con parámetros)
    EmpleadoTiempoCompleto etc2("Carlos Ruiz", "EMP-002", 20000.0, 40, 2000.0);
    std::cout << "Empleado tiempo completo (constructor con parámetros):" << std::endl;
    etc2.mostrarInformacion();
    std::cout << "Salario total: " << etc2.calcularSalarioTotal() << std::endl << std::endl;

    // Actualizar datos y mostrar de nuevo
    etc2.actualizarBono(3000.0);
    std::cout << "Después de actualizar bono:" << std::endl;
    etc2.mostrarInformacion();
    std::cout << "Salario total: " << etc2.calcularSalarioTotal() << std::endl;

    system("pause"); // Evita que la ventana se cierre inmediatamente

    return 0;
}