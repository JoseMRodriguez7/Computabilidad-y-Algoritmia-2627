// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 14/10/2026
// Archivo symbol.h: Definición de la clase Symbol.

#pragma once

#include <iostream>

/**
 * @class Symbol
 * @brief Clase que representa un símbolo individual de un alfabeto.
 */
class Symbol {
 public:
  /**
   * @brief Constructor por defecto.
   */
  Symbol() = default;
  /**
   * @brief Constructor que inicializa el símbolo con un carácter.
   * @param c Carácter que representará al símbolo.
   */
  explicit Symbol(char c) : symbol_(c) {}

  /**
   * @brief Obtiene el carácter que representa al símbolo.
   * @return char Carácter del símbolo.
   */
  char get_symbol() const { return symbol_; }

  /**
   * @brief Sobrecarga del operador menor que.
   * Necesario para poder insertar objetos Symbol ordenados dentro de un std::set o std::map.
   * @param other El otro símbolo a comparar.
   * @return true si este símbolo es menor que el otro, false en caso contrario.
   */
  bool operator<(const Symbol& other) const {
    return symbol_ < other.symbol_;
  }

  /**
   * @brief Sobrecarga del operador de inserción en flujo.
   * @param os Flujo de salida.
   * @param sym Símbolo a imprimir.
   * @return std::ostream& Referencia al flujo de salida.
   */
  friend std::ostream& operator<<(std::ostream& os, const Symbol& sym) {
    os << sym.symbol_;
    return os;
  }

 private:
  char symbol_; /// Carácter ASCII que almacena el valor real del símbolo.
};