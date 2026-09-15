// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo p01_single_grades.cc: Implementacion de la clase GradeManager.

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "p01_single_grades.h"

void GradeManager::ReadFile(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.is_open()) {
    std::cerr << "Error al abrir el archivo: " << filename << "\n";
    return;
  }

  std::string alumno;
  double nota;

  // Lee directamente separando por espacios. 
  // 'alumno' recoge el texto, 'nota' recoge el número decimal.
  while (input_file >> alumno >> nota) {
    // Mandamos el alumno y la nota al método que decide si se guarda o no
    InsertGrade(alumno, nota);
  }
  input_file.close();
}

void GradeManager::InsertGrade(const std::string& student, double grade) {
  // Buscamos si el alumno ya existe en el mapa
  auto it = grades_.find(student);
  
  if (it != grades_.end()) { 
    // EL ALUMNO YA EXISTE.
    // it->second representa la nota que ya estaba guardada.
    // 'grade' es la nota nueva que acabamos de leer.
    if (grade > it->second) { 
      it->second = grade; // Actualizamos la nota porque la nueva es mayor
    }
  } else {
    // EL ALUMNO NO EXISTE EN EL MAPA.
    // Lo insertamos por primera vez.
    grades_.insert({student, grade});
  }
}

void GradeManager::DisplayMaxGrades() const {
  const char SPACE = ' ';
  
  // Iterar por el multimap agrupando por la clave (alu)
  for (const auto& it : grades_) {
    std::cout << it.first << SPACE << it.second << std::endl;
  }
}