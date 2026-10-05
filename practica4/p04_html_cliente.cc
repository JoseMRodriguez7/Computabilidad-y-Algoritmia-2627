// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 04/10/2026
// Archivo p04_html_cliente.cc: Programa cliente

#include <iostream>
#include <string>
#include "html_analyzer.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cerr << "Modo de empleo: ./p04_html_analyzer pagina.html esquema.txt\n";
    std::cerr << "Pruebe './p04_html_analyzer --help' para mas informacion.\n";
    return 1;
  }

  std::string input_file = argv[1];

  if (argc == 2 && input_file == "--help") {
    std::cout << "Analizador HTML mediante Expresiones Regulares.\n"
              << "Uso: ./p04_html_analyzer <fichero_html_entrada> <fichero_txt_salida>\n";
    return 0;
  }

  std::string output_file = argv[2];
  
  HtmlAnalyzer analyzer(input_file);
  
  if (!analyzer.Analyze()) {
    std::cerr << "Error al leer el archivo de entrada: " << input_file << "\n";
    return 1;
  }

  if (!analyzer.WriteReport(output_file)) {
    std::cerr << "Error al escribir en el archivo: " << output_file << "\n";
    return 1;
  }

  return 0;
}