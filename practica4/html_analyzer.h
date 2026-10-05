// Universidad de La Laguna
// Escuela Superior de Ingenierı́a y Tecnologı́a
// Grado en Ingenierı́a Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 04/10/2026
// Archivo html_analyzer.h: Definicion de la clase html_analyzer y sus métodos
#pragma once

#include <string>
#include <vector>
#include "tags.h"

// Estructura para almacenar los comentarios[cite: 62]
struct Comment {
  int start_line;
  int end_line;
  std::string text;
  bool is_description;
};

class HtmlAnalyzer {
 public:
  HtmlAnalyzer(const std::string& input_filename);

  // Metodo principal para procesar el HTML mediante regex
  bool Analyze();
  
  // Metodo para escribir el fichero de salida
  bool WriteReport(const std::string& output_filename) const;

 private:
  std::string filename_;
  std::string content_;
  
  // Elementos estructurales
  bool has_html_{false};
  bool has_head_{false};
  bool has_body_{false};
  bool has_doctype_{false};
  std::string description_;
  
  std::vector<Tags> tags_list_;
  std::vector<Comment> comments_list_;

  // Metodo auxiliar para calcular en que linea cae una posicion del texto
  int GetLineNumber(size_t position) const;
};