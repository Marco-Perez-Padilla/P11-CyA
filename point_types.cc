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

** Archivo point_types.cc: Implementación de operadores de point_types
**      Contiene las sobrecargas de los operadores necesarios para puntos y vector de puntos
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#include "point_types.h"

#include <iomanip>


/**
* @brief Overload of << operator for point_vector type
* @param ostream
* @param point_vector
* @return ostream
**/
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
  os << ps.size() << std::endl;

  for (const CyA::point &p : ps) {
    os << p << std::endl;
  }

  return os;
}


/**
* @brief Overload of << operator for point type
* @param ostream
* @param point
* @return ostream
**/
std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first << "\t" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second;

  return os;
}


/**
* @brief Overload of >> operator for point_vector type
* @param istream
* @param point_vector
* @return istream
**/
std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
  double n;
  is >> n;

  ps.clear();

  for (int i = 0; i < n; ++i) {
    CyA::point p;
    is >> p;

    ps.push_back(p);
  }

  return is;
}


/**
* @brief Overload of >> operator for point type
* @param istream
* @param point
* @return istream
**/
std::istream& operator>>(std::istream& is, CyA::point& p) {
  is >> p.first >> p.second;

  return is;
}