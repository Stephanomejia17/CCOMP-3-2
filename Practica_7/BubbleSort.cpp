#include <iostream>
int mayorque(int a, int b){
  if(a>b) return 1;
  return 0;
}
int menorque(int a, int b){
  if(a<b) return 1;
  return 0;
}
int comparar(int a, int b,int(*p)(int,int)){
  return p(a,b);
}
int absoluto(int a, int b,int(*p)(int,int)){
  a = abs(a);
  b = abs(b);
  return p(a,b);
}

void BubbleSort(int* A,int n, int(*p)(int,int,int(*)(int,int)),int(pComp)(int,int)){
  int i,j, temp;
  for(i=0;i<n;i++)
    for(j=0;j<n-1;j++){
      if(p(A[j],A[j+1],pComp)){
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
}

typedef int(*PF1)(int,int,int(*)(int,int));
typedef int(*PF2)(int,int);

int main() {
  const int dim1=4;const int dim2=5;
  int A[]={6,2,-8,3,-5};
  int B[]={3,2,7,1,14};
  int C[]={-5,-2,18,3,4};
  int D[]={10,14,13,-4,1};
  int* vectores[dim1] ={A,B,C,D}; 
  PF1 comparadores[2] = {comparar,absoluto};
  PF2 comparaciones[2] = {mayorque,menorque};
  PF1* ppff1 = comparadores;
  PF2* ppff2 = comparaciones;
  int op1[dim1]= {1,0,0,1};
  int op2[dim1]= {0,1,0,1};
  int* pop1 = op1; 
  int* pop2 = op2;  
  int **pvectores = vectores;

  std::cout <<"Vectores Desordenados\n";
  for(int** p=vectores;p<vectores+dim1;p++){
    for(int* q=*p;q<*p+dim2;q++){
      std::cout <<*q<<",";
    }
    std::cout <<"\n";
  }  
  for(int i =0; i <dim1; i++)
  { 
    BubbleSort(*pvectores,dim2, *(ppff1+*pop1),*(ppff2+*pop2));
    pop1++;
    pop2++;
    pvectores++;
  }
  std::cout <<"Vectores Ordenados\n";
  for(int** p=vectores;p<vectores+dim1;p++){
    for(int* q=*p;q<*p+dim2;q++){
      std::cout <<*q<<",";
    }
    std::cout <<"\n";
  } 
}