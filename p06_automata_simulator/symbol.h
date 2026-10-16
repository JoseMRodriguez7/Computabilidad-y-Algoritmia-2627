// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_symbol.h: Definición de la clase Symbol.

#pragma once

#include <iostream>

class Symbol {
 public:
  Symbol() = default;
  explicit Symbol(char c) : symbol_(c) {}

  char get_symbol() const { return symbol_; }

  // Necesario para insertar Símbolos en un std::set
  bool operator<(const Symbol& other) const {
    return symbol_ < other.symbol_;
  }

  // Sobrecarga de salida
  friend std::ostream& operator<<(std::ostream& os, const Symbol& sym) {
    os << sym.symbol_;
    return os;
  }

 private:
  char symbol_;
};