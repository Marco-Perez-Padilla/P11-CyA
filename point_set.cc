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

** Archivo point_set.cc: Implementación de la clase point_set
**      Contiene las implementaciones de la clase point_set
**      
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      06/12/2024 - Creacion del código

**/

#include "point_set.h"

#include <algorithm>
#include <cmath>
#include <map>


/**
* @brief Calculates the euclidean distance in an arc (between its two points)
* @param arc whose euclidean distance we are interested in
* @return double, euclidean distance
**/
double point_set::euclidean_distance(const CyA::arc& a) const {
  double dx = a.first.first - a.second.first;
  double dy = a.first.second - a.second.second;

  return sqrt(dx * dx + dy * dy);
}


/**
* @brief Computes a tree total cost
* @return double, total cost
**/
double point_set::compute_cost(void) const {
  double total_cost {0.0};

  for (const CyA::arc& arc : emst_) {
    total_cost += euclidean_distance (arc);
  }

  return total_cost;
}


/**
* @brief Method to merge two trees
* @param forest. Vector of trees
* @param arc to unit both trees
* @param int i, index of first tree to merge
* @param int j, index of second tree to merge
**/
void point_set::merge_subtrees(forest& st, const CyA::arc &a, int i, int j) const {
  CyA::weigthed_arc merging_arc (euclidean_distance(a), a); // Preparing the weighted arc so we can use the merge method
  st[i].merge(st[j], merging_arc); // Merging

  st.erase(st.begin() + j); // Erasing the selected tree
}


/**
* @brief Method to find  the indixes of the subtrees in a forest that contain the nodes of a given arc. If none is found, the forest has got no incident subtrees
* @param forest. Vector of trees
* @param arc to be checked
* @param int i, index of first tree 
* @param int j, index of second tree 
**/
void point_set::find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const {
  i = -1;
  j = -1;

  if (st.empty()) {
    std::cerr << "Error: El bosque está vacío." << std::endl; // Error in case forest is empty
    return;
  }

  for (long unsigned int k {0}; k < st.size(); ++k) { // Iteraring through every tree
    const EMST::sub_tree& subtree = st[k];

    if (subtree.contains(a.first)) { // If we fins an incident subtree 
      if (i == -1) { // If it's the first one found
        i = k;
      } else {
        j = k; // If it's the second one
      }
    } else if (subtree.contains(a.second)) {
      if (i == -1) {
        i = k;
      } else {
        j = k;
      }
    } 
    
    if (i != -1 && j != -1) { // If we've already found first and second, break
      break;
    }
  }

  if (i == -1 || j == -1) { // If any of them haven't been found, we restore the values to -1
    i = -1;
    j = -1;
  }
}


/**
* @brief Method that uses the euclidean distance to compute the arc vector
* @param arc_vector where to store the arcs
**/
void point_set::compute_arc_vector(CyA::arc_vector &av) const {
  av.clear();
 
  const int n = size();
 
  for (int i = 0; i < n - 1; ++i) {
    const CyA::point &p_i = (*this)[i];
 
    for (int j = i + 1; j < n; ++j) {
      const CyA::point &p_j = (*this)[j];
 
      const double dist = euclidean_distance(std::make_pair(p_i, p_j));
 
      av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
    }
  }
 
  std::sort(av.begin(), av.end());
}


/**
* @brief Method that generates the minimum tree. It uses the rest of methods
**/
void point_set::EMST(void) {
  CyA::arc_vector av;
  compute_arc_vector(av);    

  forest st;

  for (const CyA::point &p : *this) {
    EMST::sub_tree s;
    s.add_point(p);

    st.push_back(s);
  }

  for (const CyA::weigthed_arc &a : av) {
    int i, j;
    find_incident_subtrees(st, a.second, i, j); 

    if (i != j) {
      merge_subtrees(st, a.second, i, j);
    }
  }

  emst_ = st[0].get_arcs();
}


/**
* @brief Method to write the tree in the standard out stream. It also prints the cost
* @param ostream 
**/
void point_set::write_tree(std::ostream &os) const {
  for (const CyA::arc& arc : emst_) {
    os << "(" << arc.first.first << ", " << arc.first.second << ") -> " << "(" << arc.second.first << ", " << arc.second.second << ")" << std::endl;
  }
  os << std::endl;
  os << compute_cost() << std::endl;
}


/**
* @brief Method to write the .DOT format to use with graphviz
* @param ostream
**/

void point_set::write_graphviz(std::ostream &os) const {
  std::map<CyA::point, int> point_map; // Map for storing index-point relation
  int i = 0; // Index

  os << "graph {\n" << std::endl;
  
  for (const CyA::arc &arc : emst_) { // For each arc
    // We get both points
    const CyA::point &point1 = arc.first;
    const CyA::point &point2 = arc.second;

    // If point1 hasn't been added to the map, we add it and print it
    if (point_map.find(point1) == point_map.end()) {
      point_map[point1] = i;
      os << "  " << point_map[point1] << " [pos = \"" << point1.first << "," << point1.second << "!\"];" << std::endl;
      ++i;
    }
    // If point2 hasn't been added to the map, we add it and print it
    if (point_map.find(point2) == point_map.end()) {
      point_map[point2] = i;
      os << "  " << point_map[point2] << " [pos = \"" << point2.first << "," << point2.second << "!\"];" << std::endl;
      ++i;
    }
  }

  os << std::endl;
  
  // For each arc
  for (const CyA::arc& arc : emst_) {
    const CyA::point &point1 = arc.first;  
    const CyA::point &point2 = arc.second; 

    // We print the map (iteration, which will be the ID, and point)
    os << " " << point_map[point1] << " -- " << point_map[point2] << std::endl;
  }

  os << "}" << std::endl;
}