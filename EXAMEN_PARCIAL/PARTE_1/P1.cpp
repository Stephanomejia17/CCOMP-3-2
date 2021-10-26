#include <iostream>

using namespace std;

void triangulo(int (*Mat)[9], int MatTam)
{
	int *ptr1 = *Mat;
  int *ptr2 = *Mat;
  int *ini = *Mat;

  int val = 0;
  ptr1 += MatTam;
  ptr2 += MatTam+1;
  int* ptr3 = ptr1;
  int* ptr4 = ptr2;
  /*for(int i = 0; i < (MatTam*MatTam) ; i++){
    
  }*/
  for(int *i = (*Mat) + (18); i < *Mat+(MatTam*MatTam) ; i++){
    *i = *(i-10)+ *(i-9);
    ptr1 += MatTam;
    ptr2 += MatTam;
    *ptr1 = *ptr3;
    val = val + (*ptr3+*ptr4);
    *ptr2 = val;
    ptr2 ++;
    *ptr2 = *ptr4;
    
  }
  


}

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

void ceros(int* m, int dim1, int dim2){
  int* p = m;
  int* q = m;
  while(p<m+(dim1*dim2)){
    while(p<q+(dim2)){
      *p = 0;
      p++;
    }
    q = q + dim2;
  }
}

int main() {
  int M[9][9];
    
  ceros(M[0],9,9);
  M[0][0]=1;
  M[1][0]=1;
  M[1][1]=1;
  
  triangulo(&M[0], 9);
  imprimir(M[0],9,9);
	return 0;
}