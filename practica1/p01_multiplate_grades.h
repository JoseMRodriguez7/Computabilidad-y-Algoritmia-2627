// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo multiple_grades_manager.h: Definición de la clase MultipleGradesManager.
// Encapsula el contenedor para mantener múltiples calificaciones por alumno.

#pragma once

#include <string>
#include <map>
#include <vector>

class MultipleGradesManager {
 public:
  // Constructor
  MultipleGradesManager() = default;
  
  // Entrada desde un fichero
  void ReadFile(const std::string& filename);

  // Añadir una calificacion individual de un estudiante
  void InsertGrade(const std::string& student, double grade);

  // Salida de las notas de cada estudiante
  void DisplayAllGrades() const;

  // Modificacion
  void MaxGrade(const std::string&) const;

 private:
  // Para guardar multiples notas usamos un vector double
  std::map<std::string, std::vector<double>> student_grades_;
};