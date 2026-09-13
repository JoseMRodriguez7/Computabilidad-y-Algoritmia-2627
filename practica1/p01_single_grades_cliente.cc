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
#include <fstream>
#include <map>
#include <sstream>
#include <string>

#include "p01_single_grades.h"

int main(int argc, char* argv[]) {

  if (argc != 2) {
    MensajeError();
    return 1;
  }

  std::string help(argv[1]);
  if (help == "--help") {
    MensajeHelp();
    return 2;
  }

  std::ifstream archivo(argv[1]);

  if (!archivo.is_open()) {
    std::cerr << "Error. No se pudo abrir el archivo" << std::endl;
    return 3;
  }

  std::string linea;
  std::map<std::string, double> notas;

  while (getline(archivo, linea)) {
    std::stringstream ss(linea);
    std::string alumno, nota;

    if (ss >> alumno && ss >> nota) {
      if (stod(nota) > notas[alumno]) {
        notas[alumno] = stod(nota);
      }
    }
  }
  archivo.close();

  MostrarMapa(notas);
  return 0;
}
