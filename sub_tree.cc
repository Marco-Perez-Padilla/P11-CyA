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

** Archivo sub_tree.cc: Implementación de la clase sub_tree
**      Contiene las implementaciones de .
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#include <iomanip>
#include <cmath>

#include <algorithm>
#include <utility>

#include "sub_tree.h"

namespace EMST {

/**
* @brief Method to add an arc to a tree, and its points to a point collection
* @param arc to be added
**/
void sub_tree::add_arc(const CyA::arc &a) {
  arcs_.push_back(a);

  points_.insert(a.first);
  points_.insert(a.second);
}


/**
* @brief Method to add a point to a point collection
* @param point to be added
**/
void sub_tree::add_point(const CyA::point &p) {
  points_.insert(p);
}


/**
* @brief Method to find out if a point is contained in a point collection
* @param point to be found
* @return bool type. True if found, false otherwise
**/
bool sub_tree::contains(const CyA::point &p) const {
  return points_.find(p) != points_.end();
}


/**
* @brief Method to merge a tree with a new weighted arc
* @param sub_tree
* @param weighted_arc
**/
void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
  arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
  arcs_.push_back(a.second);

  points_.insert(st.points_.begin(), st.points_.end());

  cost_ += a.first + st.get_cost();
}
}