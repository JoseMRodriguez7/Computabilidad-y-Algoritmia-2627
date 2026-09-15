// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo p01_single_grades_cliente.cc: programa cliente.
// Usa la clase GradeManager para mostrar la calificacion maxima por estudiante.

#include <iostream>
#include <string>

#include "p01_single_grades.h"

int main(int argc, char* argv[]) {

  if (argc == 1 || std::string(argv[1]) == "--help") {
    std::cout << "Modo de empleo: ./p01_single_grades grades.txt\n"
              << "El fichero debe contener lineas con el formato: <alu> <nota>\n"
              << "El programa mostrara la calificacion maxima por estudiante.\n";
    return 1;
  }

  if (argc != 2) {
    std::cerr << "Pruebe './p01_single_grades --help' para mas informacion.\n";
    return 1;
  }

  std::string filename = argv[1];
  GradeManager manager;
  
  manager.ReadFile(filename);
  manager.DisplayMaxGrades();

  // Opción para insertar elementos de forma individual
  std::string new_student;
  double new_grade;
  std::cout << "\nInserte un nuevo registro individual (alu nota): ";
  if (std::cin >> new_student >> new_grade) {
    manager.InsertGrade(new_student, new_grade);
    manager.DisplayMaxGrades();
  }

  return 0;
}