// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_strings.h: Definición de la clase String y sus métodos.
// 

#pragma once

#include <iostream>
#include <string>

class String {
  public:
    // Constructor por defecto
    String() = default;
    // Método para leer el archivo
    void ReadFile(const std::string&);
    void InsertString(const std::string&, const std::string&);
    // Método para escribir un archivo
    void WriteFile(const std::string&);
    // Operaciones pedidas en la practica
    void Alfabeto();
    void Longitud();
    void Inversa();
    void Prefijos();
    void Sufijos();
    void Validacion();
  private:
  // Usamos std::vector para almacenar la pareja de strings de cadena y alfabeto
  std::set<std::pair<std::string, std::string>> string_;
};