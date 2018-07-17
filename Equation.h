#ifndef _EQUATION_
#define _EQUATION_

#include <vector>
#include "Molecule.h"

class Equation
  {
    private:
      vector<float> X;
      vector<Molecule> lhm;
      vector<Molecule> rhm;
      vector<vector<int>> coefficient_mat;
      void update_matrix(); //.cc
      void update_mol_coeff(); //.cc
      vector<string> distinct_elemments();
      bool elemment_in_list(const string& elemment, const vector<string>& list);
    public:
      Equation(const string& str); //.cc
      ~Equation(){;}
      void normalize(bool debug); //.cc
      void print_matrix(); //.cc
      void print();

  };
#endif
