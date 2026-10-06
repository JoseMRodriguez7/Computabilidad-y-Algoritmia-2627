// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_chain.cc.h: Implementacion de la clase Chain y sus métodos.
// 

#include "p02_chain.h"
#include "p02_symbol.h"
#include "p02_language.h"

#include <iostream>
#include <algorithm>

int Chain::Length() const {
  if (chain_.size() == 1 && chain_[0] == '&') {
    return 0;
  }
  return chain_.size();
}

Chain Chain::Reverse() const {
  std::string inversa(chain_);
  std::reverse(inversa.begin(), inversa.end());
  return Chain(inversa);
}

Language Chain::Prefixes() const {
  Language result;
  result.Insert(Chain("&"));
  if (Length() > 0) {
    std::string current_prefix;
    for (char c : chain_) {
      current_prefix += c;
      result.Insert(Chain(current_prefix));
    }
  }
  return result;
}

Language Chain::Suffixes() const {
  Language result;
  result.Insert(Chain("&"));
  
  if (Length() > 0) {
    for (size_t i = 0; i < chain_.size(); ++i) {
      result.Insert(Chain(chain_.substr(i)));
    }
  }
  return result;
}

// Modificacion
Chain Chain::Concatenar(const std::string& new_chain) const {
  std::string result(chain_);
  if (new_chain.empty()) {
    result += "&";
    return Chain(result);
  }
  result += new_chain;
  Alphabet new_alphabet(result);
  Chain concatenado(result);
  return concatenado;
}

bool Chain::IsValid(const Alphabet& alphabet) const {
  if (Length() == 0) return true;
  
  for (char c : chain_) {
    if (!alphabet.Contains(Symbol(c))) {
      return false;
    }
  }
  return true;
}

bool Chain::operator<(const Chain& other) const {
  if (Length() != other.Length()) {
    return Length() < other.Length();
  }
  return chain_ < other.chain_;
}

std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  os << chain.chain_;
  return os;
}