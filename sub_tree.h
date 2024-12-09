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

** Archivo sub_tree.h: Declaración de la clase sub_tree
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#ifndef SUB_TREE_H
#define SUB_TREE_H

#include <iostream>
#include <cmath>

#include "point_types.h"

namespace EMST {
class sub_tree {
 private:
  // Private atributes
  CyA::tree arcs_;
  CyA::point_collection points_;
  double cost_;

 public:
  // Constructor
  sub_tree(void): arcs_(), points_(), cost_(0) {}
  // Destructor
  ~sub_tree(void) {}
  // Methods
  void add_arc(const CyA::arc &a);
  void add_point(const CyA::point &p);
  bool contains(const CyA::point &p) const;
  void merge(const sub_tree &st, const CyA::weigthed_arc &a);
  // Getters
  inline const CyA::tree& get_arcs(void) const { return arcs_; }
  inline double get_cost(void) const { return cost_; }
};

typedef std::vector<sub_tree> sub_tree_vector;
}

#endif