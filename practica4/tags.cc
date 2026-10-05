// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 04/10/2026
// Archivo tags.cc: Implementacion de la clase Tags

#include <iostream>

#include "tags.h"

// Constructor
Tags::Tags(const std::string& name, int line, bool is_closing)
    : name_(name), line_(line), is_closing_(is_closing) {}

const std::string& Tags::Getname() const { return name_; }
int Tags::Getline() const { return line_; }
bool Tags::is_closing() const { return is_closing_; }

const std::vector<Attribute>& Tags::GetAttribute() const {
  return attributes_;
}

bool Tags::HasAttribute() const { return !attributes_.empty(); }
int Tags::countAttribute() const { return attributes_.size(); }
void Tags::AddAttribute(const Attribute& attr) { attributes_.push_back(attr); }