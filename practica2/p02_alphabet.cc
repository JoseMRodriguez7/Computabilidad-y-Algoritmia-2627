// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_alphabet.h: Implementacion de la clase Alphabet.

#include "p02_alphabet.h"

Alphabet::Alphabet(const std::string& symbols) {
  for (char c : symbols) {
    symbols_.insert(Symbol(c)); // Requiere que Symbol tenga un constructor con char
  }
}

bool Alphabet::Contains(const Symbol& symbol) const {
  return symbols_.find(symbol) != symbols_.end();
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{";
  auto it = alphabet.symbols_.begin();
  while (it != alphabet.symbols_.end()) {
    os << *it;
    ++it;
    if (it != alphabet.symbols_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}