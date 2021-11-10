#include <iostream>

class Comparador{ //Creamos la Clase Comparador
  public:
    int a; int b; //Variables
    Comparador(int _a, int _b){ //Este es mi constructor de la clase
      a = _a;
      b = _b;
    }
    int mayorque(int c, int d){ 
      //Aqui asignaremos los valores pasados a la funcion a mis variables de la clase, que serian a y b
      a = c;
      b = d;
      if(a>b) return 1; //Utilizando mis variables de la clase
        return 0;
    }
    int menorque(int c, int d){
      //Aqui asignaremos los valores pasados a la funcion a mis variables de la clase, que serian a y b
      a = c;
      b = d;
      if(a<b) return 1;
      return 0;
    }
    int comparar(int c, int d,Comparador *obj,int(Comparador::*p)(int,int)){ //Recibe dos enteros, un objeto de mi Clase Comparador y un puntero a metodo de la clase
      //Aqui asignaremos los valores pasados a la funcion a mis variables de la clase, que serian a y b
      a = c;
      b = d;
      return (obj->*p)(a,b);
    } 
    int absoluto(int c, int d,Comparador *obj,int(Comparador::*p)(int,int)){//Recibe dos enteros, un objeto de mi Clase Comparador y un puntero a metodo de la clase
      //Aqui asignaremos los valores pasados a la funcion a mis variables de la clase, que serian a y b
      a = abs(c); //En este caso al ser valor absoluto a las variables pasadas por parametro de la funcion les sacaremos su valor absoluto
      b = abs(d);
      return (obj->*p)(a,b);
    }
};
void BubbleSort(int* A,int n,Comparador *obj ,int(Comparador::*p)(int, int, Comparador *, int(Comparador::*)(int,int)),int(Comparador::*pComp)(int,int)){
  //Mi bubblesort recibe un puntero, un entero, mi objeto de tipo Comparador, un puntero a metodo de clase (Comparar o Absoluto), y por ultimo otro puntero a metodo (mayorque o menorque)
  int i,j, temp;
  for(i=0;i<n;i++)
    for(j=0;j<n-1;j++){
      if((obj->*p)(A[j],A[j+1],obj,pComp)){ //Usamos mi objeto para "ejecutar" mi metodo de la clase
        //Intercambio
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
}
//Tipos definidos para mis 2 distintos punteros a metodo
typedef int(Comparador::*PF1)(int, int, Comparador *,int(Comparador::*)(int,int));
typedef int(Comparador::*PF2)(int,int);

int main() {
  const int dim1=4;const int dim2=5;
  int A[]={6,2,-8,3,-5};
  int B[]={3,2,7,1,14};
  int C[]={-5,-2,18,3,4};
  int D[]={10,14,13,-4,1};
  int* vectores[dim1] ={A,B,C,D}; 
  //Arrays de metodos
  PF1 comparadores[2] = {&Comparador::comparar,&Comparador::absoluto};
  PF2 comparaciones[2] = {&Comparador::mayorque,&Comparador::menorque};
  //Punteros a mis arrays de metodos
  PF1* ppff1 = comparadores;
  PF2* ppff2 = comparaciones;
  //Operaciones
  int op1[dim1]= {1,0,0,1};
  int op2[dim1]= {0,1,0,1};
  //Punteros de mis operaciones
  int* pop1 = op1; 
  int* pop2 = op2;  
  //doble puntero a mis arrays
  int **pvectores = vectores;
  //Y creamos un objeto de tipo Comparador
  Comparador* obj;
  //Impresion de mis vectores desordenados
  std::cout <<"Vectores Desordenados\n";
  for(int** p=vectores;p<vectores+dim1;p++){
    for(int* q=*p;q<*p+dim2;q++){
      std::cout <<*q<<",";
    }
    std::cout<<"\n";
  }  
  //Ordenamiento
  for(int i =0; i <dim1; i++)
  { 
    BubbleSort(*pvectores,dim2, obj,*(ppff1+*pop1),*(ppff2+*pop2)); 
    pop1++;
    pop2++;
    pvectores++;
  }
  //Impresion de mis vectores ordenados
  std::cout <<"Vectores Ordenados\n";
  for(int** p=vectores;p<vectores+dim1;p++){
    for(int* q=*p;q<*p+dim2;q++){
      std::cout <<*q<<",";
    }
    std::cout <<"\n";
  } 
  
}