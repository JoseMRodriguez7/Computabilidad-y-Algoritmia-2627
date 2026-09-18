// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_strings.cc: Implementación de la clase String.
// 

#include <fstream>
#include <string>

#include "p02_strings.h"

void String::ReadFile(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.open()) {
    std::cerr << "Error: No se pudo abrir el archivo" << std::endl;
    return;
  }

  std::string chain, alphabet;
  while (input_file >> chain >> alphabet) {
    InsertGrade(chain, alphabet);
  }
}

void String::InsertString(const std::string& chain, const std::string& alphabet) {
  std::pair<std::string, std::string> string(chain, alphabet);
  string_.pushback(string);
}

void String::WriteFile(const std::string& filename) {
  std::ofstream output(filename);
  
}
