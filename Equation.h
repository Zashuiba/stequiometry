#ifndef _EQUATION_
#define _EQUATION_

#include <vector>
#include "Molecule.h"

class Equation
  {
    private:
      vector<Molecule> lhm;
      vector<Molecule> rhm;
      vector<vector<int>> coefficient_mat;
      void update_matrix(); //.cc
      vector<string> distinct_elemments();
      bool elemment_in_list(const string& elemment, const vector<string>& list);
    public:
      Equation(const string& str); //.cc
      ~Equation(){;}
      void normalize(); //.cc
      void print_matrix(); //.cc

  };
#endif
