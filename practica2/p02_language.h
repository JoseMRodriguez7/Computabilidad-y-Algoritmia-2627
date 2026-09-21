// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_language.h: Definición de la clase Language y sus métodos.

#pragma once

#include <iostream>
#include <set>
#include "p02_chain.h"

class Language {
 public:
  Language() = default;

  // Inserta una nueva cadena en el lenguaje
  void Insert(const Chain& chain);

  // Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& os, const Language& language);

 private:
  std::set<Chain> chains_; // Almacena las cadenas ordenadas y sin duplicados
};