/*
COO Sparse Matrix Test using Linked List implementation.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using Scalar = int;

//////////////////////////////////////////////////

class DenseMatrix {
private:
  std::vector<std::vector<Scalar>> data;
  uint nrows;
  uint ncols;

public:

  DenseMatrix(std::istream& input) {
    while(input.good()) {
      std::string line;
      getline(input, line);
      std::istringstream stream(line);
      std::vector<Scalar> row;
      while(stream.good()) {
        Scalar value;
        stream >> value;
        row.push_back(value);
      }
      data.push_back(row);
    }
    nrows = data.size();
    ncols = data[0].size();
  }

////

  Scalar& operator()(uint i, uint j) {
    return data[i][j];
  }

  Scalar operator()(uint i, uint j) const {
    return data[i][j];
  }

////

  void print() const {
    for(auto const& row : data) {
        for(auto const& val : row) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
  }

////

  bool is_square() const {
    return nrows == ncols;
  }

////

  uint get_nrows() const {return nrows;}
  uint get_ncols() const {return ncols;}
};

//////////////////////////////////////////////////

class SparseMatrix {
private:
  struct Element {
    uint i;
    uint j;
    Scalar v;
    Element* next;
  };
  Element* head = nullptr;
  int const nrows;
  int const ncols;

public:

  SparseMatrix(uint nrows, uint ncols) :
    nrows(nrows),
    ncols(ncols) {
  }
  
  SparseMatrix(DenseMatrix const& dmat) :
   nrows(dmat.get_nrows()),
   ncols(dmat.get_ncols()) {
    Element* p;
    for(uint i=0; i<dmat.get_nrows(); ++i) {
      for(uint j=0; j<dmat.get_ncols(); ++j) {
        if(dmat(i,j) != 0) {
          if(head == nullptr) {
            head = new Element{i, j, dmat(i,j), nullptr};
            p = head;
          } else {
            p->next = new Element{i, j, dmat(i,j), nullptr};
            p = p->next;
          }
        }
      }
    }
  }

////

  ~SparseMatrix() {
    while(head != nullptr) {
      Element* l = head;
      head = head->next;
      delete l;
    }
  }

////

  void print() const {
    Element* p = head;
    while(p != nullptr) {
      std::cout << "(" << p->i << ", " << p->j << ") = " << p->v << std::endl;
      p = p->next;
    }
    std::cout << std::endl;
  }

////

  SparseMatrix minorM(uint ri, uint rj) const {
    // we want to create a sparsematrix that does not contain the ith row 
    // elements or the jth row elements and then return a reference to the
    // head of that matrix
    SparseMatrix M(nrows-1, ncols-1);
    Element* m = nullptr;
    Element* p = head;

    while(p != nullptr){
      if(p->i != ri && p->j != rj){

        uint i = p->i;
        if(p->i > ri) {--i;}
        uint j = p->j;
        if(p->j > rj) {--j;}
        
        if(M.head == nullptr){
          M.head = new Element{i, j, p->v, nullptr};
          m = M.head;
        }
        else{
          m->next = new Element{i, j, p->v, nullptr};
          m = m->next;
        }
      }
      
      p = p->next;
    }
    
    return M;
  }
  
  ///////

  uint sparseGet(uint i, uint j, Element* head) const{
    // will return 0 if the element is not in the sparse matrix, otherwise
    // will return the value of the element
    Element* tmp = head;
    while(tmp != nullptr){
      if(tmp->i == i && tmp->j == j)
        return tmp->v;
      tmp = tmp->next;
    }
    return 0;
  }

  //////

  Scalar determinant() const {
    if(nrows == 1)
      return head->v;
  }
};

//////////////////////////////////////////////////

int main() {
  std::istringstream input("1 0 0\n3 0 0\n6 0 0"); //comment this for stepik
  // std::istream& input = std::cin; // uncomment this for stepik
  // std::istringstream input("1"); //comment this for stepik

  DenseMatrix dmat(input);
  dmat.print();
  assert(dmat.is_square());

  SparseMatrix smat(dmat);
  smat.print();

  smat.minorM(0,0).print();

  return -1;
}
