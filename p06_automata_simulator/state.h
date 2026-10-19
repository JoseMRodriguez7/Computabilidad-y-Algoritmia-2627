// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/10/2026
// Archivo state.h: Definición de la clase State.

#pragma once

#include <iostream>
#include <map>
#include "alphabet.h"

/**
 * @class State
 * @brief Clase que representa un estado individual dentro de un Autómata Finito Determinista (DFA).
 */
class State {
  public:
    /**
     * @brief Constructor de la clase State.
     * @param identifier Número entero que identifica de forma unívoca al estado.
     * @param alphabet Referencia al alfabeto del autómata para validar las transiciones.
     * @param accepting_state Booleano que indica si es un estado final/de aceptación.
     */
    State(int identifier, const Alphabet& alphabet, bool accepting_state);

    /**
     * @brief Añade una nueva transición desde este estado hacia otro.
     * Solo se añadirá si el símbolo pertenece al alfabeto.
     * @param symbol Símbolo que acciona la transición.
     * @param destination_id Identificador del estado destino.
     */
    void AddTransition(const Symbol& symbol, int identifier);
    
    /**
     * @brief Calcula hacia qué estado se transita dado un símbolo de entrada.
     * @param symbol Símbolo leído por el autómata.
     * @return int Identificador del estado destino, o -1 si la transición no existe (estado de muerte).
     */
    int Transit(const Symbol& symbol);

    /**
     * @brief Verifica si los estados a los que van las transiciones existen
     * @param total_states número total de estados del autómata
     * @return Verdadero si exiten, falso si no
     */
    bool CheckTransitions(int total_states) const;

    /**
     * @brief Obtiene el identificador numérico del estado.
     * @return int Identificador del estado.
     */
    int Identifier() const;

    /**
     * @brief Indica si el estado es de aceptación.
     * @return true si es estado de aceptación, false si no lo es.
     */
    bool IsAcceptance() const;
  private:
    int identifier_;                     /// Identificador numérico único del estado.
    Alphabet alphabet_;                  /// Alfabeto asociado para validar transiciones entrantes.
    bool accepting_state_;               /// Bandera que define si el estado es final (de aceptación).
    std::map<Symbol, int> transitions_;  /// Mapa que relaciona símbolos de entrada con identificadores de estados destino.
};