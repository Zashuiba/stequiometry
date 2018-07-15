#include "Solver.h"
#include <cmath>


void Solver::print_matrix(const vector<vector<int> > &mat) const
  {
    for (unsigned int i = 0; i < mat.size(); i++)
      {
        for (unsigned int j = 0; j < mat[i].size(); j++)
          cout << mat[i][j] << " ";
        cout << endl;
      }
  }


void Solver::determine_mat(vector<vector<int>> &mat) //will affect b
  {
    for (unsigned int i = 0; i < mat.size(); i++)
      this->b.push_back(0);
    unsigned int i = 0;
    while (mat.size() != mat[0].size())
      {
        vector<int> row;
        for (unsigned int j = 0; j < mat[0].size(); j++)
          {
            if (j == i)
              row.push_back(1);
            else
              row.push_back(0);
          }
        this->b.push_back(1);
        mat.push_back(row);
        i++;
      }
  }

bool Solver::integer_in_list(int a, const vector<int> &vec)
  {
    for (unsigned int i = 0; i < vec.size(); i++)
      {
        if (vec[i] == a)
          return true;
      }
    return false;
  }

void Solver::calc_p(vector<vector<int>>& mat) //will also affect the b vector
  {
    unsigned int n = mat.size();
    //template for P: (all 0's)
    for (unsigned int i = 0; i < n; i++)
      {
        vector<int> row;
        for (unsigned int j = 0; j < n; j++)
          {
            row.push_back(0);
          }
        P.push_back(row);
      }
    vector<int> used_rows;
    vector<int> ordered_indexes;
    for (unsigned int j = 0; j < n; j++)
      {
        //calculate the ordered indexes
        for (unsigned int i = 0; i < n; i++)
          ordered_indexes.push_back(i);
        //bubble sorting
        for (unsigned int i = 0; i < (n - 1); i++)
          {
            if (mat[ordered_indexes[i]][j] <= mat[ordered_indexes[i + 1]][j])
              {
                int aux = ordered_indexes[i + 1];
                ordered_indexes[i + 1] = ordered_indexes[i];
                ordered_indexes[i] = aux;
              }
          }
        for (unsigned int i = 0; i < ordered_indexes.size(); i++)
          {
            if (!integer_in_list(ordered_indexes[i], used_rows))
              {
                used_rows.push_back(ordered_indexes[i]);
                P[j][ordered_indexes[i]] = 1;
                ordered_indexes.clear();
                break;
              }
          }
      }
  }

void Solver::decompose(vector<vector<int>> &mat)
  {
    //make templates for U and L
    for (unsigned int i = 0; i < mat.size(); i++)
      {
        vector<float>row;
        for (unsigned int j = 0; j < mat[0].size(); j++)
          {
            row.push_back(0);
          }
        L.push_back(row);
        U.push_back(row);
      }

    int n = mat.size();
    float sum;
    int p, k, i, j;
    for(k=0;k<n;k++)
      {
          U[k][k]=1;
          for(i=k;i < n;i++)
          {
              sum=0;
              for(p=0;p<=k - 1;p++)
                  sum+=L[i][p]*U[p][k];
              L[i][k]=mat[i][k]-sum;
          }

          for(j=k+1;j<n;j++)
          {
              sum=0;
              for(p=0;p <= k - 1;p++)
                  sum+=L[k][p]*U[p][j];
              U[k][j]=(mat[k][j]-sum)/L[k][k];
          }
      }

  }

void Solver::print_float_mat(const vector<vector<float>>& float_mat) const
  {
    for (unsigned int i = 0; i < float_mat.size(); i++)
      {
        for (unsigned int j = 0; j < float_mat.size(); j++)
          cout << float_mat[i][j] << " ";
        cout << endl;
      }
  }


vector<int> Solver::solve(vector<vector<int>>& mat)
  {
    vector<int> sol;
    determine_mat(mat);
    cout << "Possible matrix with solution : " << endl;
    print_matrix(mat);
    cout << endl << "Vector b :" << endl;
    print_vector(b);
    cout << endl;
    calc_p(mat);
    cout << "Permutation matrix : " << endl; print_matrix(P); cout << endl;
    return sol;
  }
