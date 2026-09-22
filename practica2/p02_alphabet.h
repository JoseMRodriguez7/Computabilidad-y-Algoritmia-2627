// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_alphabet.h: Definición de la clase Alphabet.

#pragma once

#include <iostream>
#include <set>
#include <string>
#include "p02_symbol.h"

class Alphabet {
 public:
  Alphabet() = default;
  // Construye el alfabeto a partir de una cadena de caracteres
  explicit Alphabet(const std::string& symbols);

  // Comprueba si un símbolo pertenece al alfabeto
  bool Contains(const Symbol& symbol) const;

  // Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

 private:
  std::set<Symbol> symbols_;
};