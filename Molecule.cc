#include "Molecule.h"
#include <cctype>

void Molecule::analyze_atom(const string &str)
  {
    string element = "";
    string bond_str = "";
    for (unsigned int i = 0; i < str.length(); i++)
      {
        if (!isdigit(str[i]))
          element += str[i];
        else
          bond_str += str[i];
      }
    if (bond_str == "")
      bond_str = "1";
    TAtom fooatom;
    fooatom.bonds = atoi(bond_str.c_str());
    fooatom.elemment = element;
    atoms.push_back(fooatom);
  }

Molecule::Molecule(short unsigned int coefficient, const string& str)
  {
    //H2O CO2 CH4 ...
    this->coefficient = coefficient;
    string atom = "";
    for (unsigned int i = 0; i < str.length(); i++)
      {
        atom += str[i];
        if (str[i + 1] == '\0'
        || (isdigit(str[i]) && !isdigit(str[i]))
        || (isupper(str[i + 1])))
          {
            analyze_atom(atom);
            atom = "";
          }
      }
  }

int Molecule::numAtoms(const string& element) const
  {
    for (unsigned int i = 0; i < atoms.size(); i++)
      {
        if (atoms[i].elemment == element)
          return atoms[i].bonds;
      }
    return 0;
  }
