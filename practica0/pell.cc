// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 0
// Autor: José Manuel Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 16/09/2025
// Archivo cya-P02-strings.cc: programa cliente.
//         Contiene la función main del proyecto que usa las clases X e Y
//         para ... (indicar brevemente el objetivo)
// Referencias:
//         Enlaces de interés
// Historial de revisiones
//         09/09/2025 - Creación (primera versión) del código

#include <iostream>
#include <cmath>

const double dos{2};
const double RAIZ_CUADRADA{std::sqrt(dos)};

int main(int argc, char* argv[]) {

  int bucle{std::stoi(argv[1])};
  double sum_0(0);

  for (int i{0}; i < bucle; i++) {
    sum_0 = (std::pow(1 + RAIZ_CUADRADA, i) 
            - std::pow(1 - RAIZ_CUADRADA, i)) / (2 * RAIZ_CUADRADA);

    std::cout << sum_0 << ' '; 
  }

  std::cout << std::endl;

  return 0;
}