// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/10/2026
// Archivo automata.h: Definición de la clase Automata.

#pragma once

#include <iostream>
#include <string>
#include <map>

#include "state.h"

/**
 * @class Automata
 * @brief Clase que simula un Autómata Finito Determinista (DFA).
 * Se encarga de leer su definición desde un fichero y simular cadenas de entrada.
 */
class Automata {
  public:
    /**
     * @brief Constructor que crea y valida el autómata a partir de un fichero de definición.
     * @param filename Ruta del fichero .dfa con la especificación del autómata.
     */
    Automata(const std::string& filename);

    /**
     * @brief Simula el comportamiento del DFA para las cadenas contenidas en un fichero.
     * Lee cada cadena, muestra la traza de transiciones y determina si es aceptada o rechazada.
     * @param filename Ruta del fichero .txt con las cadenas de entrada a evaluar.
     */
    void Simulate(const std::string& filename);

    /**
     * @brief Imprime por pantalla si el DFA tiene estados de absorción 
     */
    void PrintAbsortionStates() const;
  private:
    std::map<int, State> states_;   /// Mapa que asocia el identificador de cada estado con su objeto State correspondiente.
    int initial_state_;             /// Identificador del estado de arranque del DFA.
    Alphabet alphabet_;             /// Alfabeto válido de entrada reconocido por el DFA.
};