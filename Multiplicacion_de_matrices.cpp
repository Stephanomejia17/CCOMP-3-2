#include <iostream>
void imprimir(int* m, int dim1, int dim2){
  int* p = m;
  int* q = m;
  while(p<m+(dim1*dim2)){
    while(p<q+(dim2)){
      std::cout << *p << " ";
      p++;
    }
    std::cout << "\n";
    q = q + dim2;
  }
}

void multiplicar(int* m,int dim1, int dim2, int* n, int dim1n, int dim2n, int*res, int dim1r, int dim2r){
  int* p = m;
  int* q = m;
  int* r = n;
  int* s = n;
  int* t = res;
  int suma;
  while(p<m+(dim1*dim2)){
    suma = 0;
    while(p<q+(dim2)){
      std::cout << *p << " ";
      std::cout << *s << " ";
      suma = suma + ((*p)*(*s));
      s = s + dim2n;
      if(s>=n+(dim1n*dim2n)){
        r = r + 1;
        s = r;
        *t = suma;
        std::cout << "\n";
        std::cout << *t << " ";
        t = t + 1;
      }
      p++;
    }
    std::cout << "\n";
    if(r>=n+dim2n){//ya se recorrio toda la segunda matriz
      q = q + dim2;
      r = n;
      s = n;
    }
    p = q; 
  }
}

int main() {
  /*int A[3][2] = {{1,2},{3,4},{5,6}};
  int B[2][3] = {{7,8,9},{10,11,12}};
  int C[3][3];
  imprimir(A[0],3,2);
  std::cout << "\n";
  imprimir(B[0],2,3);
  std::cout << "\n";
  multiplicar(A[0],3,2,B[0],2,3,C[0],3,3);
  std::cout << "\n";
  imprimir(C[0],3,3);*/

  int A[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
  int B[3][2] = {{13,14},{15,16},{17,18}};
  int C[4][2];
  imprimir(A[0],4,3);
  std::cout << "\n";
  imprimir(B[0],3,2);
  std::cout << "\n";
  multiplicar(A[0],4,3,B[0],3,2,C[0],4,2);
  std::cout << "\n";
  imprimir(C[0],4,2);
}