// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/10/2026
// Archivo state.h: Implementacion de la clase State.

#pragma once

#include <iostream>
#include <map>
#include "alphabet.h"

class State {
  public:
    /// Constructor por defecto
    State(int identifier, const Alphabet& alphabet, bool accepting_state);

    /// Añade una transición al estado
    void AddTransition(const Symbol& symbol, int identifier);
    /// Ver hacia donde transita con un símbolo del alfabeto
    int Transit(const Symbol& symbol);
    bool CheckTransitions(int total_states) const;

    /// Getters
    int Identifier() const;
    bool IsAcceptance() const;
  private:
    int identifier_;
    Alphabet alphabet_;
    bool accepting_state_;
    std::map<Symbol, int> transitions_;
};