#ifndef _SOLVER_
#define _SOLVER_

#include <vector>
#include <iostream>
using namespace std;

class Solver
  {
    private:
      vector<int> b;
      vector<vector<float>> L;
      vector<float> Y;
      vector<float> X;
      vector<vector<float>> U;
      vector<vector<int>> P;
      void determine_mat(vector<vector<int>>& mat); //.cc
      void print_matrix(const vector<vector<int>>& mat) const; //.cc
      void print_float_mat(const vector<vector<float>>& float_mat) const ; //.cc

      void print_vector(const vector<int>& vec) const{
        for (unsigned int i = 0; i < vec.size(); i++)
          cout << vec[i] << " ";
        cout << endl;
      }

      void print_vector_float(const vector<float>& vec) const{
        for (unsigned int i = 0; i < vec.size(); i++)
          cout << vec[i] << " ";
        cout << endl;
      }

      bool integer_in_list(int a, const vector<int>& vec);
      void decompose(vector<vector<int>>& mat);
      void calc_p(vector<vector<int>>& mat);
      void permute_mat(vector<vector<int>>& mat) const; //.cc
      void permute_vec(vector<int>& vec); //.cc
      void calc_Y();
      void calc_X();

    public:
      Solver(){;}
      ~Solver(){;}
      vector<float> solve(vector<vector<int>>& mat, bool debug); //.cc
  };
#endif
