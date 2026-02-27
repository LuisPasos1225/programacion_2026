#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    std::string placa; // Nuevo atributo solicitado

public:
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int anio, std::string placa);

    void actualizarMarca(std::string nuevaMarca);
    void actualizarModelo(std::string nuevoModelo);
    void actualizarAnio(int nuevoAnio);
    void actualizarPlaca(std::string nuevaPlaca); // Para el reto

    virtual void mostrarInformacion(); // Se recomienda virtual para herencia

    std::string obtenerMarca();
    std::string obtenerModelo();
    int obtenerAnio();
    std::string obtenerPlaca();
};

#endif