// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 04/10/2026
// Archivo html_analyzer.cc: Implementación de la clase html_analyzer.
#include "html_analyzer.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>

HtmlAnalyzer::HtmlAnalyzer(const std::string& input_filename)
    : filename_(input_filename) {}

int HtmlAnalyzer::GetLineNumber(size_t position) const {
  // Cuenta los saltos de linea hasta la posicion encontrada
  return std::count(content_.begin(), content_.begin() + position, '\n') + 1;
}

bool HtmlAnalyzer::Analyze() {
  std::ifstream file(filename_);
  if (!file.is_open()) return false;

  std::stringstream buffer;
  buffer << file.rdbuf();
  content_ = buffer.str();
  file.close();

  // 1. Detectar DOCTYPE
  std::regex doctype_regex(R"(<!DOCTYPE\s+html>)", std::regex_constants::icase);
  std::smatch match;
  if (std::regex_search(content_, match, doctype_regex)) {
    has_doctype_ = true;
  }

  // 2. Detectar Comentarios multilínea o de una línea
  std::regex comment_regex(R"(<!--((?:.|\n|\r)*?)-->)");
  auto comments_begin = std::sregex_iterator(content_.begin(), content_.end(), comment_regex);
  auto comments_end = std::sregex_iterator();

  for (std::sregex_iterator i = comments_begin; i != comments_end; ++i) {
    std::smatch c_match = *i;
    Comment comment;
    comment.start_line = GetLineNumber(c_match.position(0));
    comment.end_line = GetLineNumber(c_match.position(0) + c_match.length(0) - 1);
    comment.text = c_match.str(0); 
    comment.is_description = false;

    if (has_doctype_ && comments_list_.empty() && comment.start_line == 2) {
      comment.is_description = true;
      description_ = c_match.str(1); 
      description_.erase(0, description_.find_first_not_of(" \n\r\t"));
      description_.erase(description_.find_last_not_of(" \n\r\t") + 1);
    }
    comments_list_.push_back(comment);
  }

  // 3. Detectar Etiquetas y atributos
  std::regex tag_regex(R"(<\s*(/?)\s*(html|head|title|body|h1|p|a|img)\b([^>]*?)>)", std::regex_constants::icase);
  auto tags_begin = std::sregex_iterator(content_.begin(), content_.end(), tag_regex);
  
  // CORRECCIÓN: Faltaba definir tags_end
  auto tags_end = std::sregex_iterator();
  
  // CORRECCIÓN: Faltaban las comillas dobles de cierre en el regex
  std::regex attr_regex(R"(([a-zA-Z\-]+)\s*=\s*"([^"]*))");

  for (std::sregex_iterator i = tags_begin; i != tags_end; ++i) {
    std::smatch t_match = *i;
    bool is_closing = (t_match.str(1) == "/");
    std::string tag_name = t_match.str(2);
    std::string attr_string = t_match.str(3);
    int line_num = GetLineNumber(t_match.position(0));

    // Estructura basica
    if (tag_name == "html" && !is_closing) has_html_ = true;
    if (tag_name == "head" && !is_closing) has_head_ = true;
    if (tag_name == "body" && !is_closing) has_body_ = true;

    Tags new_tag(tag_name, line_num, is_closing);

    // Si tiene atributos y no es de cierre, iteramos sobre los atributos
    if (!is_closing && !attr_string.empty()) {
      auto attr_begin = std::sregex_iterator(attr_string.begin(), attr_string.end(), attr_regex);
      
      // CORRECCIÓN: Crear un iterador de fin específico para los atributos
      auto attr_end = std::sregex_iterator(); 
      for (std::sregex_iterator a = attr_begin; a != attr_end; ++a) {
        std::smatch a_match = *a;
        new_tag.AddAttribute({a_match.str(1), a_match.str(2)});
      }
    }
    tags_list_.push_back(new_tag);
  }
  return true;
}

bool HtmlAnalyzer::WriteReport(const std::string& output_filename) const {
  std::ofstream out(output_filename);
  if (!out.is_open()) return false;

  out << "PROGRAM: " << filename_ << "\n";
  if (!description_.empty()) {
    out << "DESCRIPTION:\n" << description_ << "\n";
  }
  
  out << "STRUCTURE:\n"
      << "HTML: " << (has_html_ ? "True" : "False") << "\n"
      << "HEAD: " << (has_head_ ? "True" : "False") << "\n"
      << "BODY: " << (has_body_ ? "True" : "False") << "\n"
      << "DOCTYPE " << (has_doctype_ ? "HTML5" : "None") << "\n\n";

  out << "TAGS:\n";
  for (const auto& tag : tags_list_) {
    out << "[Line " << tag.Getline() << "] " 
        << (tag.is_closing() ? "/" : "") << tag.Getname() << "\n";
  }

  out << "\nATTRIBUTES:\n";
  for (const auto& tag : tags_list_) {
    if (tag.HasAttribute()) {
      out << "[Line " << tag.Getline() << "] " << tag.Getname() << "\n";
      for (const auto& attr : tag.GetAttribute()) {
        out << attr.name << "=\"" << attr.value << "\"\n";
      }
      out << "\n";
    }
  }

  out << "COMMENTS:\n";
  for (const auto& comment : comments_list_) {
    if (comment.is_description) {
      out << "[Line " << comment.start_line << "] DESCRIPTION\n";
    } else {
      if (comment.start_line == comment.end_line) {
        out << "[Line " << comment.start_line << "]\n";
      } else {
        out << "[Line " << comment.start_line << "-" << comment.end_line << "]\n";
      }
    }
    out << comment.text << "\n";
  }
  return true;
}