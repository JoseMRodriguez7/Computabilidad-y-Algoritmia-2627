// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo p01_multiple_grades.cc: programa cliente.
// Usa la clase MultipleGradesManager para agrupar notas.

#include <iostream>
#include <string>
#include "p01_multiplate_grades.h"

int main(int argc, char* argv[]) {
  
  if (argc == 1 || std::string(argv[1]) == "--help") {
    std::cout << "Modo de empleo: ./p01_multiple_grades grades.txt\n"
              << "El fichero debe contener lineas con el formato: <alu> <nota>\n"
              << "El programa agrupara y mostrara todas las calificaciones por estudiante.\n";
    return 1;
  }

  if (argc > 4) {
    std::cerr << "Pruebe './p01_multiple_grades --help' para mas informacion.\n";
    return 1;
  }

  std::string filename{argv[1]};
  MultipleGradesManager manager;
  
  manager.ReadFile(filename);

  if (argc == 4) {
      if (std::string(argv[2]) == "--max") {
      manager.MaxGrade(std::string(argv[3]));
    }
  } else {
    manager.DisplayAllGrades();

    // Opción para insertar elementos de forma individual
    std::string new_student;
    double new_grade;
    std::cout << "\nInserte un nuevo registro individual (alu nota): ";
    if (std::cin >> new_student >> new_grade) {
      manager.InsertGrade(new_student, new_grade);
      manager.DisplayAllGrades();
    }
  }
  return 0;
}