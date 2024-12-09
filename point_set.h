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

** Archivo point_set.h: Declaración de la clase point_set
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#ifndef POINT_SET_H
#define POINT_SET_H

#include "sub_tree.h"

typedef std::vector<EMST::sub_tree> forest;

class point_set : public CyA::point_vector {
 private:
  CyA::tree emst_; // Private atribute

  // Private methods
  double euclidean_distance(const CyA::arc& a) const;
  double compute_cost(void) const;
  void merge_subtrees(forest& st, const CyA::arc &a, int i, int j) const;
  void find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const;
  void compute_arc_vector(CyA::arc_vector &av) const;
  
 public:
  // Constructor
  point_set(const CyA::point_vector &points) : CyA::point_vector(points), emst_() {}
  // Destructor
  ~point_set(void) = default;
  // Methods
  void EMST(void);
  // Write methods
  void write_tree(std::ostream &os) const;
  void write(std::ostream &os) const;       // ????
  void write_graphviz(std::ostream &os) const;
  // Getters
  inline const CyA::tree& get_tree(void) const { return emst_; }
  inline const CyA::point_vector& get_points(void) const { return *this; }
  inline const double get_cost(void) const { return compute_cost(); }
};

#endif