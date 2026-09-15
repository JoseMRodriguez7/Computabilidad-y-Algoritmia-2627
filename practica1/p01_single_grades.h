// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo p01_single_grades.h: Definicion de la clase GradeManager.
// Guarda la calificacion maxima de cada estudiante en un contenedor asociativo.

#pragma once

#include <iostream>
#include <map>
#include <string>

class GradeManager {
  public:
    // Constructores
    GradeManager() = default;
   
    // Añadir una calificacion individual de un estudiante
    void InsertGrade(const std::string& student, double grade);

    // E/S
    // Entrada desde un fichero
    void ReadFile(const std::string& filename);

    // Salida de la maxima nota de cada estudiante
    void DisplayMaxGrades() const;

  private:
    std::map<std::string, double> grades_;

};