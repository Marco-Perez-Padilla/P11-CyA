/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Computabilidad y Algoritmia
** Curso: 2º
** Practica 11: Algoritmos Voraces
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 06/12/2024

** Archivo kruskal.cc: Programa cliente.
**      Contiene las implementaciones de .
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#include <cstring>
#include <fstream>
#include "point_set.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include "point_set.h"
#include "check_functions.h"

int main(int argc, char* argv[]) {
  if (argc < 2 || argc > 4) {
    Usage();
    return 1;
  } else if (argc == 2 && std::string(argv[1]) == "-h") {
    Help();
    return 0;
  }

  std::ifstream input_file(argv[1]);
  if (!input_file.is_open()) {
    std::cerr << "Data file: " << argv[1] << " couldn't be opened" << std::endl;
    return 1;
  }

  CyA::point_vector points;
  input_file >> points;
  input_file.close();  

  point_set ps(points);

  ps.EMST();                   

  bool generate_dot = false;
  std::string dot_file_name = "output.dot"; 

  if (argc > 2) {
    for (int i = 2; i < argc; ++i) {
      if (std::string(argv[i]) == "-d") {
        generate_dot = true;
        if (i + 1 < argc) {
          dot_file_name = argv[i + 1];  
        }
        break;
      }
    }
  }

  if (generate_dot) {
    std::ofstream dot_file(dot_file_name);
    if (dot_file.is_open()) {
      ps.write_graphviz(dot_file);
      dot_file.close();
    } else {
      std::cerr << "File: " << dot_file_name << " couldn't be opened" << std::endl;
      return 1;
    }
  }

  ps.write_tree(std::cout);

  return 0;
}
