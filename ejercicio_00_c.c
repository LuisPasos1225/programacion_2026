#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ESTUDIANTES 100
#define MAX_LONGITUD 100

// Estructura para guardar datos del estudiante
typedef struct {
    char nombre[MAX_LONGITUD];
    char codigo[MAX_LONGITUD];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

// Variables globales
Estudiante estudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;

// ============= FUNCIONES DE ACTUALIZACIÓN =============
void actualizarNombre(int indice, char nuevoNombre[]) {
    if (indice >= 0 && indice < totalEstudiantes) {
        strcpy(estudiantes[indice].nombre, nuevoNombre);
        printf("✓ Nombre actualizado correctamente.\n");
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void actualizarCodigo(int indice, char nuevoCodigo[]) {
    if (indice >= 0 && indice < totalEstudiantes) {
        strcpy(estudiantes[indice].codigo, nuevoCodigo);
        printf("✓ Código actualizado correctamente.\n");
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void actualizarEdad(int indice, int nuevaEdad) {
    if (indice >= 0 && indice < totalEstudiantes) {
        if (nuevaEdad > 0 && nuevaEdad < 120) {
            estudiantes[indice].edad = nuevaEdad;
            printf("✓ Edad actualizada correctamente.\n");
        } else {
            printf("✗ Edad inválida.\n");
        }
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void actualizarPromedio(int indice, float nuevoPromedio) {
    if (indice >= 0 && indice < totalEstudiantes) {
        if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
            estudiantes[indice].promedio = nuevoPromedio;
            printf("✓ Promedio actualizado correctamente.\n");
        } else {
            printf("✗ Promedio debe estar entre 0.0 y 10.0.\n");
        }
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void actualizarActivo(int indice, bool nuevoEstado) {
    if (indice >= 0 && indice < totalEstudiantes) {
        estudiantes[indice].activo = nuevoEstado;
        printf("✓ Estado actualizado correctamente.\n");
    } else {
        printf("✗ Índice inválido.\n");
    }
}

// ============= FUNCIONES DE VISUALIZACIÓN =============
void mostrarNombre(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        printf("Nombre: %s\n", estudiantes[indice].nombre);
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void mostrarCodigo(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        printf("Código: %s\n", estudiantes[indice].codigo);
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void mostrarEdad(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        printf("Edad: %d años\n", estudiantes[indice].edad);
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void mostrarPromedio(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        printf("Promedio: %.2f\n", estudiantes[indice].promedio);
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void mostrarActivo(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        if (estudiantes[indice].activo) {
            printf("Estado: Activo\n");
        } else {
            printf("Estado: Inactivo\n");
        }
    } else {
        printf("✗ Índice inválido.\n");
    }
}

void mostrarInformacionCompleta(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        printf("\n========== INFORMACIÓN COMPLETA ==========\n");
        printf("Nombre: %s\n", estudiantes[indice].nombre);
        printf("Código: %s\n", estudiantes[indice].codigo);
        printf("Edad: %d años\n", estudiantes[indice].edad);
        printf("Promedio: %.2f\n", estudiantes[indice].promedio);
        if (estudiantes[indice].activo) {
            printf("Estado: Activo\n");
        } else {
            printf("Estado: Inactivo\n");
        }
        printf("==========================================\n\n");
    } else {
        printf("✗ Índice inválido.\n");
    }
}

// ============= FUNCIONES DEL MENÚ =============
void agregarEstudiante() {
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        printf("✗ No se pueden agregar más estudiantes (límite alcanzado).\n");
        return;
    }

    printf("\n--- AGREGAR NUEVO ESTUDIANTE ---\n");
    
    printf("Nombre: ");
    fgets(estudiantes[totalEstudiantes].nombre, MAX_LONGITUD, stdin);
    estudiantes[totalEstudiantes].nombre[strcspn(estudiantes[totalEstudiantes].nombre, "\n")] = 0;

    printf("Código: ");
    fgets(estudiantes[totalEstudiantes].codigo, MAX_LONGITUD, stdin);
    estudiantes[totalEstudiantes].codigo[strcspn(estudiantes[totalEstudiantes].codigo, "\n")] = 0;

    printf("Edad: ");
    scanf("%d", &estudiantes[totalEstudiantes].edad);

    printf("Promedio (0.0 - 10.0): ");
    scanf("%f", &estudiantes[totalEstudiantes].promedio);

    printf("¿Activo? (1=Sí, 0=No): ");
    int activo;
    scanf("%d", &activo);
    estudiantes[totalEstudiantes].activo = (activo == 1);

    getchar(); // Limpiar buffer

    totalEstudiantes++;
    printf("✓ Estudiante agregado correctamente.\n\n");
}

void mostrarEstudiantePorIndice() {
    if (totalEstudiantes == 0) {
        printf("✗ No hay estudiantes registrados.\n");
        return;
    }

    printf("\n--- MOSTRAR ESTUDIANTE ---\n");
    printf("Total de estudiantes: %d\n", totalEstudiantes);
    printf("Ingrese el índice (0 a %d): ", totalEstudiantes - 1);
    
    int indice;
    scanf("%d", &indice);
    getchar();

    mostrarInformacionCompleta(indice);
}

void mostrarTodosEstudiantes() {
    if (totalEstudiantes == 0) {
        printf("✗ No hay estudiantes registrados.\n");
        return;
    }

    printf("\n========== TODOS LOS ESTUDIANTES ==========\n");
    for (int i = 0; i < totalEstudiantes; i++) {
        printf("\n[%d] %s\n", i, estudiantes[i].nombre);
        printf("    Código: %s\n", estudiantes[i].codigo);
        printf("    Edad: %d años\n", estudiantes[i].edad);
        printf("    Promedio: %.2f\n", estudiantes[i].promedio);
        printf("    Estado: %s\n", estudiantes[i].activo ? "Activo" : "Inactivo");
    }
    printf("==========================================\n\n");
}

void mostrarMenu() {
    printf("\n========== SISTEMA DE GESTIÓN DE ESTUDIANTES ==========\n");
    printf("1. Agregar estudiante\n");
    printf("2. Mostrar un estudiante en específico\n");
    printf("3. Mostrar todos los estudiantes\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
}

int main() {
    int opcion;

    while (1) {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                mostrarEstudiantePorIndice();
                break;
            case 3:
                mostrarTodosEstudiantes();
                break;
            case 4:
                printf("✓ ¡Hasta luego!\n");
                return 0;
            default:
                printf("✗ Opción inválida. Intente de nuevo.\n");
        }
    }

    return 0;
}
