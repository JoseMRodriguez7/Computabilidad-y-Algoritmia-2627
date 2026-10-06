// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: José Manuel Rodríguez Rodríguez
// Correo: alu0101815671@ull.edu.es
// Fecha: 17/09/2025
// Archivo p02_strings_cliente.cc: Programa principal (cliente).

#include <iostream>
#include <fstream>
#include <string>
#include "p02_alphabet.h"
#include "p02_chain.h"
#include "p02_language.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode"
              << " (palabra a concatenar)\n"
              << "Pruebe ’./p02_strings --help’ para más información.\n";
    return 1;
  }

  if (argc == 2 || std::string(argv[1]) == "--help") {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode"
              << " (palabra a concatenar)\n"
              << "Codigos de operacion:\n"
              << "  1: Alfabeto\n"
              << "  2: Longitud\n"
              << "  3: Inversa\n"
              << "  4: Prefijos\n"
              << "  5: Sufijos\n"
              << "  6: Validacion (OK/ERROR)\n"
              << "  7: Concatenar\n";
    return 0;
  }

  if (argc > 5) {
    std::cerr << "Pruebe './p02_strings --help' para mas informacion.\n";
    return 1;
  }

  std::ifstream input_file(argv[1]);
  std::ofstream output_file(argv[2]);
  const int opcode = std::stoi(argv[3]);
  std::string nueva_cadena;

  if (!input_file.is_open() || !output_file.is_open()) {
    std::cerr << "Error al abrir los ficheros.\n";
    return 1;
  }

  if (opcode == 7) {
    if (argc != 5) {
      std::cerr << "Error. no existe la cadena a concatenar\n";
      return 1;
    } else {
      nueva_cadena = argv[4];
    }
  }
  std::string chain_str, alpha_str;
  while (input_file >> chain_str >> alpha_str) {
    Alphabet alphabet(alpha_str);
    Chain chain(chain_str);

    switch (opcode) {
      case 1:
        output_file << chain << ": " << alphabet << std::endl;
        break;
      case 2:
        output_file << chain.Length() << std::endl;
        break;
      case 3:
        output_file << chain << " -> " << chain.Reverse() << std::endl;
        break;
      case 4:
        output_file << chain.Prefixes() << std::endl;
        break;
      case 5:
        output_file << chain.Suffixes() << std::endl;
        break;
      case 6:
        output_file << (chain.IsValid(alphabet) ? "OK" : "ERROR") 
                    << std::endl;
        break;
      case 7:
        output_file << chain << ": " << chain.Concatenar(nueva_cadena)
                    << std::endl;
        break;
      default:
        std::cerr << "Codigo de operacion " << opcode << " no valido.\n";
        return 1;
    }
  }

  return 0;
}