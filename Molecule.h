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
      short unsigned int coefficient;
      void analyze_atom(const string& str);
    public:
      Molecule(short unsigned int coefficient, const string& str); //.cc
      ~Molecule(){};
      vector<TAtom> getAtoms() const {return atoms;}
      short unsigned int getCoeff() const {return coefficient;}
      int numAtoms(const string&  element) const; //.cc
      unsigned int getNumAtoms() const {return atoms.size();}

  };
#endif
