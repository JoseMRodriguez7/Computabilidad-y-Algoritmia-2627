// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/10/2026
// Archivo automata.h: Implementacion de la clase Automata.

#pragma once

#include <iostream>
#include <string>
#include <map>

#include "state.h"

class Automata {
  public:
    /// Constructor
    Automata(const std::string& filename);
    /// Simulador de la construcción de una cadena
    void Simulate(const std::string& filename);
  private:
    std::map<int, State> states_;
    int initial_state_;
    Alphabet alphabet_;
};