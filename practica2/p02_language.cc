// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_language.cc: Implementacion de la clase Language y sus métodos.

#include "p02_language.h"

void Language::Insert(const Chain& chain) {
  chains_.insert(chain);
}

std::ostream& operator<<(std::ostream& os, const Language& language) {
  if (language.chains_.empty()) {
    os << "{}";
    return os;
  }
  
  os << "{";
  auto it = language.chains_.begin();
  while (it != language.chains_.end()) {
    os << *it;
    ++it;
    if (it != language.chains_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}