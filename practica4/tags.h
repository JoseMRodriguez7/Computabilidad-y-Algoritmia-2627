// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 04/10/2026
// Archivo tags.h: Definicion de la clase Tags y sus métodos

#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Attribute {
  std::string name;
  std::string value;
};

class Tags {
  public:
    // Constructor
    Tags(const std::string& name, int line, bool is_closing);
    // Getters
    const std::string& Getname() const;
    int Getline() const;
    bool is_closing() const;
    const std::vector<Attribute>& GetAttribute() const;
    // Metodos
    bool HasAttribute() const;
    int countAttribute() const;
    void AddAttribute(const Attribute& attr);
  private:
    std::string name_;
    int line_;
    bool is_closing_;
    std::vector<Attribute> attributes_;
};