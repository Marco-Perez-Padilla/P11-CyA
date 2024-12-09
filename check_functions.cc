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

** Archivo check_functions.cc: Implementación de las funciones de ayuda
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código
**/

#include <iostream>
#include "check_functions.h"


/**
 * @brief Prints Help to the user
 */
void Help () {
    std::cout << "./kruskal -- Kruskal algorithm\n"
              << "Usage:          ./kruskal filein.txt [-d [fileout.dot]]\n"
              << "\n"
              << "filein.cc:       Input file with the data of the graph\n"
              << "[-d [fileout.txt]]:     If -d is used, a .dot file will be created for its visualization in Graphviz\n"
              << "\n";
}

/**
 * @brief Prints how to use the program
 */
void Usage() {
  std::cout << "How to use: ./kruskal filein.txt [-d [fileout.dot]]\n"
            << "Try 'kruskal --help' for further information\n";
}