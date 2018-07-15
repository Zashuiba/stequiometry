#include "Equation.h"
#include <iostream>

int main()
  {
    static const string mole_str = "H2Oxy";
    Molecule mole(1, mole_str);
    static const string equ_str = "CH4 + O2 --> CO2 + H2O";
    Equation equ(equ_str);
    equ.normalize();
    return 0;
  }
