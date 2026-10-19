// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 14/10/2026
// Archivo alphabet.h: Definición de la clase Alphabet.

#pragma once

#include <iostream>
#include <set>
#include <string>
#include "symbol.h"

/**
 * @class Alphabet
 * @brief Clase que representa un alfabeto como un conjunto finito de símbolos válidos.
 */
class Alphabet {
 public:
  /**
   * @brief Constructor por defecto.
   */
  Alphabet() = default;

  /**
   * @brief Constructor que crea el alfabeto a partir de una cadena de caracteres.
   * @param symbols Cadena de texto donde cada carácter será un símbolo del alfabeto.
   */
  explicit Alphabet(const std::string& symbols);

  /**
   * @brief Comprueba si un símbolo concreto pertenece al alfabeto.
   * @param symbol Símbolo que se desea buscar.
   * @return true si el símbolo es parte del alfabeto, false en caso contrario.
   */
  bool Contains(const Symbol& symbol) const;

  /**
   * @brief Sobrecarga del operador de inserción para imprimir el alfabeto.
   * @param os Flujo de salida.
   * @param alphabet Alfabeto a imprimir.
   * @return std::ostream& Referencia al flujo de salida.
   */
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

 private:
  std::set<Symbol> symbols_; /// Conjunto de símbolos únicos que conforman el alfabeto.
};