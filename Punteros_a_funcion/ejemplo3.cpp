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
void BubbleSort(int A[],int n, int(*p)(int,int,int(*)(int,int)),int(pComp)(int,int)){
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
int main() {
  int A[]={6,2,-8,3,-5};
  int(*pComp)(int,int) = menorque;
  int(*p)(int,int,int(*)(int,int)) = comparar;//Putenro a Funcion que recibe un puntero a funcion.
  BubbleSort(A,5,p,pComp);
  for(int i=0;i<5;i++) std::cout <<A[i];
  std::cout <<"\n";
}