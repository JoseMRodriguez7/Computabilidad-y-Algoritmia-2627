// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/10/2026
// Archivo state.cc: Implementacion de la clase State.

#include <iostream>
#include "state.h"
#include "alphabet.h"

State::State(int identifier, const Alphabet& alphabet, bool accepting_state) :
  identifier_(identifier), alphabet_(alphabet), accepting_state_(accepting_state) {}

void State::AddTransition(const Symbol& symbol, int identifier) {
  if (alphabet_.Contains(symbol))
    transitions_.insert({symbol, identifier});
}

int State::Transit(const Symbol& symbol) {
  auto it = transitions_.find(symbol);

  if (it != transitions_.end())
    return it->second; /// identificador destino
  /// si no hay identificador destino, devuelve un error en salida
  return -1;
}

bool State::CheckTransitions(int total_states) const {
  for (const auto& pair : transitions_) {
    int destiny = pair.second;
    if (destiny < 0 || destiny >= total_states) {
      return false; 
    }
  }
  return true;
}

/// Getters
int State::Identifier() const { return identifier_; }
bool State::IsAcceptance() const { return accepting_state_; }