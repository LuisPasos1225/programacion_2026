#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream> // Para leer el archivo .env
#include "json.hpp"

using json = nlohmann::json;

// Función para buscar la clave en el archivo .env
std::string obtenerApiKeyDesdeEnv() {
    std::ifstream envFile(".env");
    std::string linea;
    if (envFile.is_open()) {
        while (std::getline(envFile, linea)) {
            // Buscamos la línea que empieza con GEMINI_API_KEY=
            if (linea.find("GEMINI_API_KEY=") == 0) {
                return linea.substr(15); // Extraemos el valor después del '='
            }
        }
        envFile.close();
    }
    return ""; // Retorna vacío si no lo encuentra
}

int main() {
    // Obtenemos la clave de forma dinámica
    std::string apiKey = obtenerApiKeyDesdeEnv();

    if (apiKey.empty()) {
        std::cerr << "Error: No se encontro el archivo .env o la clave GEMINI_API_KEY." << std::endl;
        std::cerr << "Crea un archivo llamado .env con: GEMINI_API_KEY=tu_clave_aqui" << std::endl;
        return 1;
    }

    while (true) {
        std::string question;
        std::cout << "\nHaz tu pregunta: ";
        std::getline(std::cin, question);

        if (question.empty()) continue;

        // Escapar comillas para el JSON
        std::string escapedQuestion = question;
        size_t pos = 0;
        while ((pos = escapedQuestion.find("\"", pos)) != std::string::npos) {
            escapedQuestion.replace(pos, 1, "\\\"");
            pos += 2;
        }

        // Construir el cuerpo de la petición (Payload)
        std::string jsonPayload = "{\"contents\":[{\"parts\":[{\"text\":\"" + escapedQuestion + "\"}]}]}";

        // Guardar en archivo temporal
        std::ofstream tempFile("temp.json");
        tempFile << jsonPayload;
        tempFile.close();

        // Comando curl (usando la clave cargada del .env)
        std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-flash-latest:generateContent?key=" + apiKey;
        std::string command = ".\\curl.exe -X POST -H \"Content-Type: application/json\" -d @temp.json \"" + url + "\" -o response.json";

        // Ejecutar curl
        int result = std::system(command.c_str());
        
        // Limpiar archivo temporal de envío
        std::remove("temp.json");

        if (result != 0) {
            std::cerr << "Error ejecutando curl. Asegurate de que curl.exe este en la carpeta." << std::endl;
            continue; 
        }

        // Leer respuesta
        std::ifstream file("response.json");
        if (!file.is_open()) {
            std::cerr << "Error abriendo response.json" << std::endl;
            continue;
        }

        std::string responseStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        // Parsear JSON
        try {
            json responseJson = json::parse(responseStr);
            if (responseJson.contains("candidates") && !responseJson["candidates"].empty()) {
                std::string answer = responseJson["candidates"][0]["content"]["parts"][0]["text"];
                std::cout << "\nRespuesta de Gemini: " << answer << std::endl;
            } else {
                std::cout << "\nNo se recibio una respuesta valida. Revisa tu API Key." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error parseando la respuesta: " << e.what() << std::endl;
        }

        // Preguntar si continuar
        std::string continuar;
        std::cout << "\n¿Que otra pregunta quieres hacer? (s/n): ";
        std::getline(std::cin, continuar);
        if (continuar != "s" && continuar != "S") {
            break;
        }
    }

    return 0;
}