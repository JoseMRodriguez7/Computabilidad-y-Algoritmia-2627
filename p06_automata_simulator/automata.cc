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

#include <iostream>
#include <fstream>
#include <sstream>

#include "automata.h"

Automata::Automata(const std::string& filename) {
  std::ifstream input_file(filename);

  if (!input_file.is_open()) {
    std::cerr << "Error al abrir el archivo\n";
    return;
  }
  std::string line;

  /// Ignoramos las lineas de comentarios
  while(std::getline(input_file, line)) {
    if (!line.empty() && line.size() >= 2 && line[0] == '/' && line[1] == '/')
      continue;
    
    if (!line.empty())
      break;
  }

  alphabet_ = Alphabet(line);

  std::getline(input_file, line);
  int states_num{std::stoi(line)};

  std::getline(input_file, line);
  initial_state_ = std::stoi(line);

  while(std::getline(input_file, line)) {
    // Protección por si hay comentarios o líneas vacías entre los estados
    if (line.empty() || (line.size() >= 2 && line[0] == '/' && line[1] == '/')) {
      continue;
    }

    std::stringstream input(line);

    int state_id;
    bool is_acceptance;
    input >> state_id >> is_acceptance;

    State state(state_id, alphabet_, is_acceptance);

    char symbol;
    int destination_id;
    while (input >> symbol >> destination_id) {
      state.AddTransition(Symbol(symbol), destination_id);
    }
    states_.insert({state_id, state});
  }

  if (states_.size() != static_cast<size_t>(states_num)) {
    std::cerr << "Error. El número de estados (" << states_.size()
              << ") no coincide con el especificado (" << states_num
              << ").\n";
    return;
  }

  if (states_.find(initial_state_) == states_.end()) {
    std::cerr << "Error: El estado inicial especificado (" << initial_state_ 
              << ") no existe en el autómata.\n";
    return;
  }

  for (const auto& pair : states_) {
    const State& state(pair.second);
    if (!state.CheckTransitions(states_num)) {
      std::cerr << "Error. El estado " << pair.first
                << " tiene transiciones a estados inexsistentes.\n";
    }
  }
}

void Automata::Simulate(const std::string& filename) {
  std::ifstream input_file(filename);
  std::string chain;

  while (std::getline(input_file, chain)) {
    std::cout << "Est. Actual  Entrada  Nuevo Est.\n";
    int current_id{initial_state_};
    for (char c : chain) {
      State actual_state = states_.at(current_id);

      std::cout << current_id << "\t\t" << c << "\t\t"
                << actual_state.Transit(Symbol(c)) << '\n';
      
      current_id = actual_state.Transit(Symbol(c));
      if (current_id == -1)
        break;
    }

    if (current_id != -1 && states_.at(current_id).IsAcceptance()) {
      std::cout << "Cadena de entrada ACEPTADA.\n";
    } else {
      std::cout << "Cadena de entrada RECHAZADA.\n";
    }
  }
}