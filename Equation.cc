#include "Equation.h"
#include "Molecule.h"
#include "Solver.h"
#include <iostream>

Equation::Equation(const string& str)
  {
    //sample string CH4 + O2 --> CO2 + H20
    unsigned int i = 0;
    string mol_str;
    bool left = true;
    while (i < str.length() + 1)
      {
        if (str[i] == '>')
          left = false;
        else
          {
            if (str[i] == ' ' || str[i] == '+'|| str[i] == '-' || str[i] == '\0')
            {
              if (mol_str != "")
              {
                Molecule mol(1, mol_str);
                if (left)
                lhm.push_back(mol);
                else
                rhm.push_back(mol);
              }
              mol_str = "";
            }
            else
              mol_str += str[i];
          }
        i++;
      }
  }

bool Equation::elemment_in_list(const string& elemment, const vector<string>& list)
  {
    for (unsigned int i = 0; i < list.size(); i++)
      if (elemment == list[i])
        return true;
    return false;
  }

vector<string> Equation::distinct_elemments()
  {
    vector<string> distinct_elemments;
    for (unsigned int i = 0; i < lhm.size(); i++)
      {
        for (unsigned int j = 0; j < lhm[i].getNumAtoms(); j++)
          {
            string this_elemment = lhm[i].getAtoms()[j].elemment;
            if (!elemment_in_list(this_elemment, distinct_elemments))
              distinct_elemments.push_back(this_elemment);
          }
      }
    return distinct_elemments;
  }

void Equation::print_matrix()
  {
    for (unsigned int i = 0; i < coefficient_mat.size(); i++)
      {
        for (unsigned int j = 0; j < coefficient_mat[i].size(); j++)
          cout << coefficient_mat[i][j] << " ";
        cout << endl;
      }
  }

void Equation::update_matrix()
  {
    for (unsigned int i = 0; i < this->distinct_elemments().size(); i++)
      {
        vector<int> row;
        for (unsigned int j = 0; j < lhm.size(); j++)
          row.push_back(lhm[j].numAtoms(distinct_elemments()[i]));
        for (unsigned int j = 0; j < rhm.size(); j++)
          row.push_back(rhm[j].numAtoms(distinct_elemments()[i]) * -1);
        this->coefficient_mat.push_back(row);
      }
  }

void Equation::normalize()
  {
    update_matrix();
    Solver solver;
    cout << endl;
    solver.solve(coefficient_mat);
  }
