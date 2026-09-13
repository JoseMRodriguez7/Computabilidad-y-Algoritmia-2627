// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Jose Manuel Rodriguez Rodriguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 13/09/2026
// Archivo p01-single-grades.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 13/09/2026 - Creacion (primera version) del codigo

#include <iostream>
#include <map>
#include <string>

#include "p01_single_grades.h"

void MensajeError() {
  std::cerr << "Error. Modo de empleo: ./p01_single_grades grades.txt\n";
  std::cout << "Pruebe ./p01_singles_grades --help para mas informacion\n";
}

void MensajeHelp() {
  std::cout << "Este programa recibe una lista de notas de alumnos\n"
            << "y muestra la máxima nota de los alumnos.\n"
            << "Haga un archivo grades.txt para poner el alumno y su\n"
            << "nota correspondiente" << std::endl;
  std::cout << "./p01_single_grades grades.txt" << std::endl;
  std::cout << "formato del fichero:" << std::endl;
  std::cout << "aluXXXXXXXXXX nota" << std::endl;
}

void MostrarMapa(const std::map<std::string, double>& notas) {
  for(const auto& n : notas) {
    std::cout << n.first << ' ' << n.second << std::endl;
  }
}