// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/10/2026
// Archivo state.h: Implementacion de la clase State.

#include <iostream>
#include <string>

#include "automata.h"

int main(int argc, char* argv[]) {
  if (argc > 3) {
    std::cerr << "Error. Use el comando --help.\n";
    return 1;
  }

  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Uso del programa\n"
              << "./programa [input.dfa] [input.txt]\n"
              << "Donde input.dfa es el archivo de texto donde se "
              << "encuentra la configuracion del DFA.\n"
              << "y input.txt es el archivo donde se encuentran las cadenas "
              << "a simular\n";
    return 0;
  } else if (argc == 2) {
    std::cerr << "Error. Use el comando --help\n";
    return 1;
  }

  std::string input(argv[1]);
  std::string chain(argv[2]);

  Automata automata(input);

  automata.Simulate(chain);

  return 0;
}