// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_chain.h: Definición de la clase Chain y sus métodos.
// 

#pragma once

#include <iostream>
#include <string>
#include "p02_alphabet.h"

class Language;

class Chain {
  public:
  // Constructor
  Chain() = default;
  explicit Chain(const std::string& sequence) : chain_(sequence) {}

  // Metodos
  int Length() const;
  Chain Reverse() const;
  Language Prefixes() const;
  Language Suffixes() const;
  
  bool IsValid(const Alphabet& alphabet) const;

  // Sobrecarga necesaria para ordenar en el std::set de Language
  bool operator<(const Chain& other) const;
  
  friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
  private:
  std::string chain_;
};