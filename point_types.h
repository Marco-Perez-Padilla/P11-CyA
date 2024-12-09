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

** Archivo point_types.h: Declaración de point_types
**      Contiene las definiciones de los tipos de datos que usaremos
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#ifndef POINT_TYPES_H
#define POINT_TYPES_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

namespace CyA {
  typedef std::pair<double, double> point;

  typedef std::pair<point, point> line;
  typedef std::vector<point> point_vector;

  typedef std::pair<point, point> arc;
  typedef std::pair<double, arc> weigthed_arc;
  typedef std::vector<weigthed_arc> arc_vector;

  typedef std::set<point> point_collection;

  typedef std::vector<arc> tree;
}

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps);
std::ostream& operator<<(std::ostream& os, const CyA::point& ps);

std::istream& operator>>(std::istream& is, CyA::point_vector& ps);
std::istream& operator>>(std::istream& is, CyA::point& ps);


#endif