// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo multiple_grades_manager.cc: Implementación de la clase MultipleGradesManager.

#include <iostream>
#include <fstream>

#include "p01_multiplate_grades.h"

void MultipleGradesManager::ReadFile(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.is_open()) {
    std::cerr << "Error al abrir el archivo: " << filename << "\n";
    return;
  }

  std::string student;
  double grade;
  while (input_file >> student >> grade) {
    InsertGrade(student, grade);
  }
  input_file.close();
}

void MultipleGradesManager::InsertGrade(const std::string& student_id, double grade) {
  student_grades_[student_id].push_back(grade);
}

void MultipleGradesManager::DisplayAllGrades() const {
  const char SPACE = ' ';
  
  for (const auto& pair : student_grades_) {
    std::cout << pair.first << ":";
    for (const double grade : pair.second) {
      std::cout << SPACE << grade;
    }
    std::cout << "\n";
  }
}