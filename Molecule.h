#ifndef _MOLECULE_
#define _MOLECULE_

#include <vector>
#include <string>

using namespace std;

typedef struct
  {
    string elemment;
    short unsigned int bonds;
  }TAtom;

class Molecule
  {
    private:
      vector<TAtom> atoms;
      float coefficient;
      void analyze_atom(const string& str);
    public:
      Molecule(short unsigned int coefficient, const string& str); //.cc
      ~Molecule(){};
      vector<TAtom> getAtoms() const {return atoms;}
      float getCoeff() const {return coefficient;}
      void setCoeff(const float& coeff) {this->coefficient = coeff;}
      int numAtoms(const string&  element) const; //.cc
      unsigned int getNumAtoms() const {return atoms.size();}
      void print(); //.cc

  };
#endif
